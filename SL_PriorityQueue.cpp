
 
#include "SL_PriorityQueue.h"  // Header file

template<class ItemType>
SL_PriorityQueue<ItemType>::SL_PriorityQueue()
{
   slistPtr = new LinkedSortedList<ItemType>();
}  // end default constructor

template<class ItemType>
SL_PriorityQueue<ItemType>::SL_PriorityQueue(const SL_PriorityQueue& pq) : 
slistPtr(pq.slistPtr)
{
}  // end copy constructor

template<class ItemType>
SL_PriorityQueue<ItemType>::~SL_PriorityQueue()
{
}  // end destructor

template<class ItemType>
bool SL_PriorityQueue<ItemType>::isEmpty() const
{
   return slistPtr->isEmpty();
}  // end isEmpty

template<class ItemType>
bool SL_PriorityQueue<ItemType>::add(const ItemType& newEntry)
{ 
   slistPtr->insertSorted(newEntry);
   return true;
}  // end add

template<class ItemType>
bool SL_PriorityQueue<ItemType>::remove()
{
   // The highest priority item is at the end of the sorted list
   return slistPtr->remove(slistPtr->getLength());
}  // end remove
   
template<class ItemType>
ItemType SL_PriorityQueue<ItemType>::peek() const 
throw(PrecondViolatedExcep)
{
   if (isEmpty())
      throw PrecondViolatedExcep("peekFront() called with empty queue.");
   
   // Priority queue is not empty; return highest priority item;
   // it is at the end of the sorted list
   return slistPtr->getEntry(slistPtr->getLength());
}  // end peek



