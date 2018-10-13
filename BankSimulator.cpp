#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include "SL_PriorityQueue.h"
#include "LinkedQueue.h"
#include "Event.h"
using namespace std;
void processArrival(Event,PriorityQueueInterface<Event>*&,QueueInterface<Event>*&,int,bool&);
void processDeparture(Event,PriorityQueueInterface<Event>*&,QueueInterface<Event>*&, int, bool&);

void processArrival(Event a,PriorityQueueInterface<Event>*& pqPtr, QueueInterface<Event>*& LPtr,int time,bool& teller)
{
	cout << "Processing an arrival event at time: " << time << endl;
	pqPtr->remove();
	
	if((LPtr->isEmpty())&& teller == true)
	{
		int trans = a.getDuration();
		time = time + trans;
		Event depart('D',time,0);
		pqPtr->add(depart);
		teller = false;
	}

	else
		LPtr->enqueue(a);
}

void processDeparture(Event d,PriorityQueueInterface<Event>*& pqPtr, QueueInterface<Event>*& LPtr, int time, bool& teller)
{
	cout << "Processing a departure event at time: " << time << endl;
	pqPtr->remove();
	if(!LPtr->isEmpty())
	{
		Event newCustomer = LPtr->peekFront();
		int trans = newCustomer.getDuration();
		time = time + trans;
		LPtr->dequeue();
		Event depart('D',time,0);
		pqPtr->add(depart);
	}

	else
		teller = true;

}

int main()
{
	bool tellerAvailable = true;
	int currentTime = 0;
	PriorityQueueInterface<Event>* eventPtr = new SL_PriorityQueue<Event>();
	QueueInterface<Event>* linePtr = new LinkedQueue<Event>();

	

	ifstream inFile;
	inFile.open("arrivals.txt");
	int arrival,transaction;

	while(!inFile.eof())
	{
		inFile >> arrival >> transaction;
		Event e('A',arrival,transaction);
		eventPtr->add(e);
	}

	while(!eventPtr->isEmpty())
	{
		Event bankEvent = eventPtr->peek();
		
		currentTime = bankEvent.getTime();

		if(bankEvent.getType() == 'A')
			processArrival(bankEvent,eventPtr,linePtr,currentTime,tellerAvailable);
		else if(bankEvent.getType() == 'D')
			processDeparture(bankEvent,eventPtr,linePtr,currentTime,tellerAvailable);
	}

	inFile.close();
	

	return 0;
}
