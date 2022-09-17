#ifndef CHARSTACK_H
#define CHARSTACK_H
const int STACK_SIZE = 1000;
#include"TreeNode.h"
#include <iostream>
using namespace std;
template<class StackType> class Stack {

 public:
    Stack() : top(-1), StackArray{} {}
	bool isEmpty()const { return top == -1; };
	bool isFull()const { return top == STACK_SIZE; };

	void push(StackType data);
	void pop();
	StackType peek() { return StackArray[top];};

private:
	StackType StackArray[STACK_SIZE];
	int top;
};

//function purpose to push a new item at the top of the stack
template<class StackType> void Stack<StackType>::push(StackType data) {
	if (isFull()) cout << "Stack OverFlow" << endl;
	else {
		StackArray[++top] = data;
	}

}//end push()

//function purpose to pop top item from stack
template<class StackType> void Stack<StackType>::Stack::pop() {
	if (isEmpty()) cout << "Stack Underflow" << endl;
	else --top;
}//end pop() 
#endif 

