#include <iostream>
#include "readyqueue.h"

using namespace std;

//You must complete the all parts marked as "TODO". Delete "TODO" after you are done.
// Remember to add sufficient comments to your code


/**
 * @brief Constructor for the ReadyQueue class.
 */
 ReadyQueue::ReadyQueue() {
    capacity = 10000;
    ar = new PCB*[capacity];
    num = 0;
 }

/**
 *@brief Destructor
*/
ReadyQueue::~ReadyQueue() {
    delete[] ar;
}

/**
 *@brief Copy Constructor
*/
ReadyQueue::ReadyQueue(const ReadyQueue& other) {
    // Allocate a new array with the same capacity
    capacity = other.capacity;
    ar = new PCB*[capacity];

    // Copy each element from the other object
    for (int i = 0; i < other.num; ++i) {
        ar[i] = new PCB(*(other.ar[i]));  // Assuming PCB has a copy constructor
    }

    // Set the number of elements
    num = other.num;
}

/**
 * @brief Add a PCB representing a process into the ready queue.
 *
 * @param pcbPtr: the pointer to the PCB to be added
 */
void ReadyQueue::addPCB(PCB *pcbPtr) {
    // When adding a PCB to the queue, you must change its state to READY.
    pcbPtr->setState(ProcState::READY);
    insert(pcbPtr);
}

/**
 * @brief Remove and return the PCB with the highest priority from the queue
 *
 * @return PCB*: the pointer to the PCB with the highest priority
 */
PCB* ReadyQueue::removePCB() {
    // When removing a PCB from the queue, you must change its state to RUNNING.
    PCB* pcb = getMax();
    pcb->setState(ProcState::RUNNING);
    return pcb;
}

/**
 * @brief Returns the number of elements in the queue.
 *
 * @return int: the number of PCBs in the queue
 */
int ReadyQueue::size() {
    return getNum();
}

std::ostream& operator<<(std::ostream& os, const PCB& pcb) {
    pcb.display();
    return os;
}

/**
 * @brief Display the PCBs in the queue.
 */
void ReadyQueue::displayAll() {

    if(num == 0) {
        cout << "none" << endl;
        return;
    }

    for(int i = 0; i < num; i++) {
        cout << *ar[i];
    }
}

PCB* ReadyQueue::getMax()
{
  //This function removes the top element and returns it.
  //You should be calling remove()
  if(num == 0) return nullptr;
  PCB* temp = ar[0];
  remove(0);
  return temp;
}

//removes ar[i], and readjusts array accordingly
void ReadyQueue::remove(int i)
{
  if(i >= num || num == 0) throw BadIndex();
  swap(ar[i], ar[num-1]);
  num--;
  if(num > 0) {
    max_heapify(i);
    //if(i > 0 && ar[(i-1)/2] < ar[i]) bubbleUp(i);
  }
}


//max heapifies tree rooted at i, making sure that the max is on top
void ReadyQueue::max_heapify(int i) {

  if(num == 0) return;

  int l = (2*i) + 1; //the index of the left child of i
  int r = (2*i) + 2; //the index of the right child of i

  int largest = i;
  if(ar[l] && l < num && ar[largest]->getPriority() < ar[l]->getPriority()) largest = l;
  if(ar[r] && r < num && ar[largest]->getPriority() < ar[r]->getPriority()) largest = r;

  //The smallest is either the right or left child. We need to exchange the parent with it.
  if(largest != i)
    {
      //exchange the 2 values
      swap(ar[i], ar[largest]);
      //There might be a violation at the position that was exchanged. Call max_heapify to fix it.
      max_heapify(largest);
    }
}

//bubbles up any violation in max-heap-ness, recursively again and again if violation occurs
void ReadyQueue::bubbleUp(int i) {
  if(i == 0) return;

  int parent = (i-1)/2;

  if(ar[parent]->getPriority() < ar[i]->getPriority()) {
    swap(ar[parent], ar[i]);
    bubbleUp(parent);
  }
}

//insert element into max heap, inserts at end and then bubbles up to avoid violation
void ReadyQueue::insert(PCB* el)
{
  if(num >= capacity) throw Overflow();
  ar[num] = el;
  bubbleUp(num);
  num++;
}

ReadyQueue& ReadyQueue::operator=(const ReadyQueue& other) {
    if (this != &other) {  //check no same
        // deallocate existing queue
        delete[] ar;

        // allocate a new array with the same capacity
        capacity = other.capacity;
        ar = new PCB*[capacity];

        // copy
        for (int i = 0; i < other.num; ++i) {
            ar[i] = other.ar[i];  // Assuming PCB has a copy constructor
        }

        // Set the number of elements
        num = other.num;
    }
    return *this;
}
