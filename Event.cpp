#include "Event.h"
#include <cstddef>

Event::Event()
{
	eventType = 'A';
	eventTime = 0;
	transactionTime = 0;
}

Event::Event(char type, int eTime, int tTime)
{
	eventType = type;
	eventTime = eTime;
	transactionTime = tTime;
}

char Event::getType()
{
	return eventType;
}

int Event::getTime()
{
	return eventTime;
}

int Event::getDuration()
{
	return transactionTime;
}

bool operator > (Event e1, Event e2)
{
	int a = e1.getTime();
	int b = e2.getTime();
	if(a > b)
		return true;
	else
		return false;
}

bool operator == (Event e1,Event e2)
{
	if(e1.getType() != e2.getType())
		return false;
	else if(e1.getTime() != e2.getTime()) 
		return false;
	else if(e1.getDuration() != e2.getDuration())
		return false;
	else
		return true;
}

bool operator != (Event e1,Event e2)
{
	if(e1.getType() != e2.getType())
		return true;
	else if(e1.getTime() != e2.getTime())
		return true;
	else if(e1.getDuration() != e2.getDuration())
		return true;
	else
		return false;
}	 
