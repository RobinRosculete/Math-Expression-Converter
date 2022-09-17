#include "treeNodeStack.h"

//function purpose to push a new item at the top of the stack
void TreeNodeStack::push(TreeNode* treeNode) {
	if (isFull()) cout << "Stack OverFlow" << endl;
	else {
		nodeStackArray[++top]->info= treeNode->info;
		nodeStackArray[top]->left= treeNode->left;
		nodeStackArray[top]->right= treeNode->right;
	}

}//end push

//function purpose to pop top item from stack
void TreeNodeStack::pop() {
	if (isEmpty()) cout << "Stack Underflow" << endl;
	else --top;
}//end pop 


//Function purpose to return the values at the top of the stack
TreeNode* TreeNodeStack::peek(){
	if (isEmpty()) {
		cout << "Tree Node stack is empty!" << endl;
		return nullptr;
	}
	else {
	return nodeStackArray[top];
	}

}
