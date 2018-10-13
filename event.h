#ifndef _EVENT_H
#define _EVENT_H

class Event
{
	public:
	   Event();
	   Event(char type, int eTime ,int tTime);
	   char getType();
	   int getTime();
	   int getDuration();

	   friend bool operator > (Event e1,Event e2);
	   friend bool operator == (Event e1,Event e2);
	   friend bool operator != (Event e1,Event e2);
	   

	private:
	   char eventType;
	   int eventTime;
	   int transactionTime;
};

	

#include "Event.cpp"
#endif


