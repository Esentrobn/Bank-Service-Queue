

#ifndef _PRIORITY_QUEUE
#define _PRIORITY_QUEUE

#include "PriorityQueueInterface.h"
#include "LinkedSortedList.h"
#include "PrecondViolatedExcep.h"

template<class ItemType>
class SL_PriorityQueue : public PriorityQueueInterface<ItemType>
{
private:
   LinkedSortedList<ItemType>* slistPtr;  // Pointer to sorted list of
                                          // items in the priority queue

public:
   SL_PriorityQueue();
   SL_PriorityQueue(const SL_PriorityQueue& pq);
   ~SL_PriorityQueue();

   bool isEmpty() const;
   bool add(const ItemType& newEntry);
   bool remove();

   /** @throw PrecondViolatedExcep if priority queue is empty. */
   ItemType peek() const throw(PrecondViolatedExcep);
}; // end SL_PriorityQueue

#include "SL_PriorityQueue.cpp"
#endif
