#ifndef QUEUE_H
#define QUEUE_H
#include "Node.h"
class Queue
{
public:
	Node* head;
	Node* tail;
	Queue();
	bool IsEmpty();
	void Enqueue(int);
	int Dequeue();
};


#endif // !QUEUE_H
