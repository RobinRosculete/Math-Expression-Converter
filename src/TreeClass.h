#ifndef TREECLASS_H
#define TREECLASS_H
#include<iostream>
#include"TreeNode.h"
#include"Stack.h"

enum OrderType{PRE_ORDER,IN_ORDER, POST_ORDER};

class TreeClass {
public:
	TreeClass():root(nullptr){}
	~TreeClass();
	TreeClass(const TreeClass& originalTree);
	void operator=(const TreeClass& orginalTree);


	bool IsEmpty()const {return root == nullptr;}
	bool IsFull()const;
	
	ItemType GetItem(ItemType item, bool& found)const;
	void PrintOrders()const;
	void PutItem(ItemType item);
	void DeleteItem(ItemType item);
   
	 void createExpressionTree(string postfixExpression);
	 TreeNode* newNode(ItemType  item);

	void MakeEmpty();
 
private:
	TreeNode* root;
	Stack<TreeNode*> treeStack;
	
};
#endif 
