/**
 * Assignment 1: priority queue of processes
 * @file readyqueue.h
 * @author ??? (TODO: your name)
 * @brief ReadyQueue is a queue of PCB's that are in the READY state to be scheduled to run.
 * It should be a priority queue such that the process with the highest priority can be selected next.
 * @version 0.1
 */
//You must complete the all parts marked as "TODO". Delete "TODO" after you are done.
// Remember to add sufficient comments to your code
#pragma once
#include "pcb.h"

/**
 * @brief A queue of PCB's that are in the READY state to be scheduled to run.
 * It should be a priority queue such that the process with the highest priority can be selected next.
 */
class ReadyQueue {
private:
    // TODO: add your private member variables here
    // choose a data structure for the ReadyQueue. No STL class is allowed.
    PCB** ar; //dynamic array
    int capacity; //the size of ar
    int num; //the number of elements I have in ar

public:
    /**
     * @brief Construct a new ReadyQueue object
     *
     */
    ReadyQueue();

    /**
     * @brief Construct a copied ReadyQueue object
     *
     */
    ReadyQueue(const ReadyQueue& other);

    /**
     * @brief Destructor
     */
    ~ReadyQueue();

	// You may add additional member functions, but don't change the definitions of the following four member functions.

    /**
     * @brief Add a PCB representing a process into the ready queue.
     *
     * @param pcbPtr: the pointer to the PCB to be added
     */
	void addPCB(PCB* pcbPtr);

    /**
     * @brief Remove and return the PCB with the highest priority from the queue
     *
     * @return PCB*: the pointer to the PCB with the highest priority
     */
	PCB* removePCB();

    /**
     * @brief Returns the number of elements in the queue.
     *
     * @return int: the number of PCBs in the queue
     */
	int size();

     /**
      * @brief Display the PCBs in the queue.
      */
	void displayAll();

    void max_heapify(int i);
    //void build_min_heap(); //no need to implement this. We won't use it for our application.
    void bubbleUp(int i);
    void insert(PCB* el);
    void remove(int i);
    PCB* getMax();
    int getNum(){return num;}
    ReadyQueue& operator=(const ReadyQueue& other);

    class Overflow{};
    class BadIndex{};
    class NotFound{};

};
