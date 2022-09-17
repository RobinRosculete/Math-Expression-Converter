#include "Queue.h"

Queue::Queue() :front(-1), rear(-1), numItemsInQueue(0) {
	for (int x = 0; x < QUEUE_SIZE; ++x) {
		QueueArray[x] = '0';
	}
}

//Function purpose to insert values at the rear of Queue
void Queue::Enqueue(ItemType expressionChar) {
	if (isFull())cout << "Queue is Full" << endl;
	else {
		QueueArray[++rear] = expressionChar;
		++numItemsInQueue;
	}
}//end Enqueue

//Function purpose to remove values at the front of the queue and return the remove vlaues
void Queue::Dequeue(ItemType& expressionChar) {
	if (isEmpty())cout << "Queue is empty, nothing to Dequeue" << endl;
	else {
		front = (front + 1) % QUEUE_SIZE;
		expressionChar = QueueArray[front];
		QueueArray[front] = '0';
		--numItemsInQueue;
	}

}//End Dequeue()

//Function purpose to clear Queue
void Queue::Clear() {

	front = QUEUE_SIZE - 1;
	rear = QUEUE_SIZE - 1;
	numItemsInQueue = 0;

}//End Clesr()

//Function purpose to diplay data in Queue
void Queue::diplay()const {
	if (isEmpty())cout << "Queue is Empty nothing to diplay" << endl;
	else {

		for (int x = 0; x < numItemsInQueue; ++x) {
			cout << QueueArray[x] << " ";

		}
	}
	

}//end Display