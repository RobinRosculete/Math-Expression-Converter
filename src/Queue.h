#ifndef QUEUE_H
#define QUEUE_H
#include<iostream>
#include"TreeNode.h"

const int QUEUE_SIZE = 1000;

class Queue {
public:
	Queue();

	void Enqueue(ItemType expressionChar);
	void Dequeue(ItemType& expressionChar);
	void Clear();


	bool isFull()const{ return this->numItemsInQueue == QUEUE_SIZE; }
	bool isEmpty()const { return this->numItemsInQueue == 0; }
	int getFtont()const { return this->front;}
	int getRear()const { return this->rear; }
	void diplay()const;


private:
	ItemType QueueArray[QUEUE_SIZE];
	int front;
	int rear;
	int numItemsInQueue;
};


#endif QUEUE_H

