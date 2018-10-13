
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include "SL_PriorityQueue.h"
#include "LinkedQueue.h"
#include "Event.h"
using namespace std;

void sortArrival(Event a, PriorityQueueInterface<Event>*& eventPtr, QueueInterface<Event>*& linePtr, int time, bool& clerk)
{
	cout << "Processing an arrival event at time: " << time << endl;
	eventPtr->remove();

	if ((linePtr->isEmpty()) && clerk == true)
	{
		int trans = a.getDuration();
		time = time + trans;
		Event depart('D', time, 0);
		eventPtr->add(depart);
		clerk = false;
	}

	else
		linePtr->enqueue(a);
}
void sortDeparture(Event d, PriorityQueueInterface<Event>*& eventPtr, QueueInterface<Event>*& linePtr, int time, bool& clerk, float& wait)
{
	cout << "Processing a departure event at time: " << time << endl;
	eventPtr->remove();
	if (!linePtr->isEmpty())
	{
		Event newCustomer = linePtr->peekFront();
		int arrival = newCustomer.getTime();
		int waitTime = time - arrival;
		wait += waitTime;
		int trans = newCustomer.getDuration();
		time = time + trans;
		linePtr->dequeue();
		Event depart('D', time, 0);
		eventPtr->add(depart);
	}

	else
		clerk = true;

}
int main()
{
	bool clerkAvailable = true;
	int currentTime = 0;
	float waitTime = 0;
	int people = 0;
	PriorityQueueInterface<Event>* eventPtr = new SL_PriorityQueue<Event>();
	QueueInterface<Event>* linePtr = new LinkedQueue<Event>();
	cout << "\tThis program simulates Bank"<<endl;
	ifstream inFile;
	inFile.open("BankLines.txt");
	int arrival, transaction;	
	while (!inFile.eof())
	{
		inFile >> arrival >> transaction;
		Event e('A', arrival, transaction);
		eventPtr->add(e);
		people++;
	}
	while (!eventPtr->isEmpty())
	{
		Event bankEvent = eventPtr->peek();
		currentTime = bankEvent.getTime();
		if (bankEvent.getType() == 'A')
		{
			sortArrival(bankEvent, eventPtr, linePtr, currentTime, clerkAvailable);
		}
		else if (bankEvent.getType() == 'D'){
			sortDeparture(bankEvent, eventPtr, linePtr, currentTime, clerkAvailable, waitTime);
		}
	}

	inFile.close();
	float averageWait = waitTime / people;
	cout << endl << "Total number of customers processed: " << people << endl;
	cout << "Average amount of time spent waiting: " << averageWait << endl;
	return 0;
}
