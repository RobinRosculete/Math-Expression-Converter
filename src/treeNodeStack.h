#ifndef TRENODESTACK_H
#define TRENODESTACK_H
#include"TreeNode.h"
#include "charStack.h"
#include"TreeNode.h"
#include <iostream>

using namespace std;
class TreeNodeStack {
public:
	TreeNodeStack() :top(-1), nodeStackArray{nullptr} {}
	bool isEmpty()const { return top == -1; };
	bool isFull()const { return top == STACK_SIZE; };

	void push(TreeNode* treeNode);
	void pop();
	TreeNode* peek() ;


private:
	TreeNode* nodeStackArray[STACK_SIZE];
	int top;
};


#endif TRENODESTACK_H
