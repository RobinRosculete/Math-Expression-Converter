#include"TreeClass.h"
#include"treeHelper.h"

//Function prupose to create a new node and return a pointer too it
TreeNode* TreeClass::newNode(ItemType item) {
	TreeNode* tempNode = nullptr;
	if (!(IsFull())) {
	 tempNode = new TreeNode;
		tempNode->left = nullptr;
		tempNode->right = nullptr;
		tempNode->info = item;

	}return tempNode;
}//end create newNode()

//Function purpose to create an expression form an postfix expression 
void TreeClass::createExpressionTree(string postFixExpression) {
	
	TreeNode* tempNodePtr1 = nullptr;
    TreeNode * tempNodePtr2 = nullptr;
	
	for (int x = 0; x < postFixExpression.length(); x++)
	{	 if (isalnum(postFixExpression[x]))
		{
			root = newNode(postFixExpression[x]);
			treeStack.push(root);
		}
		else 
		{
			root = newNode(postFixExpression[x]);

			tempNodePtr1 = treeStack.peek(); 
			treeStack.pop();  

			tempNodePtr2 = treeStack.peek();
			treeStack.pop();

			root->right = tempNodePtr1;
			root->left = tempNodePtr2;
		
			treeStack.push(root);
		}
	}	
	root = treeStack.peek();
	treeStack.pop();
}//end createExpressionTree()

TreeClass::TreeClass(const TreeClass& originalTree) {
	try {
		CopyTree(root, originalTree.root);
	}catch(bad_alloc& ex) {
	cout << "Exception: " << ex.what() << endl;
	}

}//end copy constructor

void TreeClass::operator=(const TreeClass& orginalTree) {
	try {
		if (&orginalTree == this) {
			Destroy(root);
			CopyTree(root, orginalTree.root);
		}
	}
	catch (bad_alloc& ex) {
		cout << "Exception: " << ex.what() << endl;
	}
}//End opertot=()


//function purpose: checking if memory is available to allocate from heap for a new node
bool TreeClass::IsFull() const{
	TreeNode* location = nullptr;
	try {
		location = new TreeNode;
		delete location;
		return false;
	}
	catch (bad_alloc& ex) {
		cout << "Exception: " << ex.what() << endl;
		return true;
	}
}//end isFull()

//Function Purpose to print content of tree by calling helper recursive fun printTree()
void TreeClass::PrintOrders()const {
	cout << "\nPreorder:  ";
	printPreorder(root);
	cout << endl;
	cout << "\nPostorder: ";
	printPostorder(root);
	cout << endl;
	cout << "\nInorder:   "; 
	printInorder(root);
	cout << endl;
}//end print() 

//function  purpose to search for item in tree by calling helper recursive fun Retrive() 
ItemType TreeClass::GetItem(ItemType item, bool& found)const {
	Retrive(root, item, found);
	return item;
	
}//end getItem()

//Destructor calling helper function destroy to free memory
TreeClass::~TreeClass() {
	Destroy(root);

}// end ~TreeClass

//Function purpose to make tree empty by calling helper functoion Destroy()
void TreeClass::MakeEmpty() {
	Destroy(this->root); 
}//End MakeEmpty()

//Function purpose to delete Node of tree
void TreeClass::DeleteItem(ItemType item) {
	Delete(root, item);
}//end DeleteItem()

//function purpose to insert item into tree by calling helper recursive function insert();
void TreeClass::PutItem(ItemType item) {
	try {
	Insert(root, item);
	}
	catch (std::bad_alloc ex) {
		cout << "Exception: " << ex.what() << endl;
	}
}//end putItem();



