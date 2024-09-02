#ifndef MAXHEAP_H
#define MAXHEAP_H
#include <iostream> //for operator<<()
using namespace std;

template <class T>
class maxHeap;

template <class T>
ostream& operator<<(ostream& o, const maxHeap<T>& h);

template <class T>
class maxHeap
{
  friend ostream& operator<< <T>(ostream& o, const maxHeap<T>& h);
private:
  T* ar; //dynamic array
  int capacity; //the size of ar
  int num; //the number of elements I have in ar
public:
  maxHeap(){ar = NULL; capacity = 0; num = 0;}
  maxHeap(int c);
  ~maxHeap(){if(ar!=NULL)delete [] ar;}
  void max_heapify(int i);
  //void build_min_heap(); //no need to implement this. We won't use it for our application.
  void bubbleUp(int i);
  void insert(const T& el);
  int find(const T& key) const;
  void remove(int i);
  T getMax();
  int getNum(){return num;}

  class Overflow{};
  class BadIndex{};
  class NotFound{};
};

template <class T>
maxHeap<T>::maxHeap(int c) {
  capacity = c;
  ar = new T[c];
  num = 0;
}

template <class T>
void exchange(T& a, T& b)
{
  T temp = a;
  a = b;
  b = temp;
}

template <class T>
void maxHeap<T>::bubbleUp(int i) {
  if(i == 0) return;

  int parent = (i-1)/2;

  if(*ar[parent] < *ar[i]) {
    exchange(ar[parent], ar[i]);
    bubbleUp(parent);
  }
}

template <class T>
void maxHeap<T>::insert(const T& el)
{
  if(num >= capacity) throw Overflow();
  ar[num] = el;
  bubbleUp(num);
  num++;
}

template <class T>
int maxHeap<T>::find(const T& key) const
{
  for(int i = 0; i < num; i++)
    if(ar[i] == key)
      return i;

  //The element doesn't exist
  throw NotFound();// "The element doesn't exist";
}

template <class T>
void maxHeap<T>::remove(int i)
{
  if(i >= num) throw BadIndex();
  exchange(ar[i], ar[num-1]);
  num--;
  max_heapify(i);
  if(i > 0 && ar[(i-1)/2] < ar[i]) bubbleUp(i);
}

template <class T>
void maxHeap<T>::max_heapify(int i) {
  int l = (2*i) + 1; //the index of the left child of i
  int r = (2*i) + 2; //the index of the right child of i

  int largest = i;
  if(l < num && *ar[largest] < *ar[l]) largest = l;
  if(r < num && *ar[largest] < *ar[r]) largest = r;

  //The smallest is either the right or left child. We need to exchange the parent with it.
  if(largest != i)
    {
      //exchange the 2 values
      exchange(ar[i], ar[largest]);
      //There might be a violation at the position that was exchanged. Call max_heapify to fix it.
      max_heapify(largest);
    }
}

template <class T>
T maxHeap<T>::getMax()
{
  //This function removes the top element and returns it.
  //You should be calling remove()
  T temp = ar[0];
  remove(0);
  return temp;
}

template <class T>
ostream& operator<<(ostream& o, const maxHeap<T>& h) {
if(h.num == 0) {
  cout << "none" << endl;
  return o;
}
for(int i = 0; i < h.num; i++) {
  T el = h.ar[i];
  cout << *el << " ";
}
cout << endl;
return o;
}

#endif
