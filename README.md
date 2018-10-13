# Bank-Service-Queue
 Bank Line Service Queue Simulation

The program starts on the main function initializing 2 different objects with 2 different names ‘enterPtr’ and ‘linePtr.’. 
‘enterPtrT’ takes all the user inputs from the text file and saves it in an organized system or in another word in a waiting line. 
The second ‘linePtr’ object is an enqueue object that is adding an item of data awaiting processing, to queues of such items.
After saving all the attendants to an object, it categories them based on arrival and transaction time, and
based up on their transaction time we send them to their corresponding classes up on checking the ‘eventPtr’.

‘SL_PriorityQueue’ class uses 4 functions including 2 constructors with different parameters

The class “LinkedQueue” consists of 4 functions including 2 constructors extending the “Node” class for queue implementation as
a chain of linked nodes. 

The class ‘event’ holds 3 private functions and 3 public functions with 3 oveloded friend operator definitions. 

The last class ‘PrecondViolatedExcep’ consists of definitions of logic errors and what happens if a run time error occurs. 
‘SortedInterface’ is the interface used to primarily define a protocol. 

used 2 nonmember functions namely ‘sortArrival ()’ that takes an event and 2 queue, and process the departure time; ‘processArival ()’ 
takes an event and 2 queue, and process the departure time.

These two functions perform multiple task to make sure all the attendants get the best customer service by utilizing a priority queue system
