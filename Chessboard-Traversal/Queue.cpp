#include "Queue.h"
#include <iostream>
using namespace std;
Queue::Queue() {
	this->head = nullptr;
	this->tail = nullptr;
}
void Queue::Enqueue(int value) {
	Node* t = (Node*)malloc(sizeof(Node));
	if (t != nullptr) {
		t->data = value;
		t->next = nullptr;
		if (this->head == nullptr) {
			this->head = t;
			this->tail = t;
		}
		else {
			this->tail->next = t;
			this->tail = t;
		}
	}
}
bool Queue::IsEmpty() {
	return(this->head == nullptr);
}
int Queue::Dequeue() {
	if (!IsEmpty()) {
		Node* ptr = this->head;
		int store = this->head->data;
		if (this->head->next == nullptr) {
			this->head = nullptr;
			this->tail = nullptr;
			delete(ptr);
			return store;
		}
		else {
			this->head = ptr->next;
			delete (ptr);
			return store;
		}
	}
	return -1;
}