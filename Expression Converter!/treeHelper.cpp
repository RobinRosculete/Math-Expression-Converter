#include"treeHelper.h"
//Helper function purpose to copy root of a tree
void CopyTree(TreeNode*& copy, const TreeNode* originalTree) {
	if (originalTree == nullptr) {
		copy = nullptr;
	}
	else {
		copy = new TreeNode;
		copy->info = originalTree->info;
		CopyTree(copy->right, originalTree->left);
		CopyTree(copy->right, originalTree->right);
	}
}//End copyTreee()

//Function purpose to print the inorder traversal of tree
void printInorder(TreeNode* tree) {
	if (tree != nullptr) {
		cout << "  (";
		printInorder(tree->left);
		cout << tree->info;
		printInorder(tree->right);
		cout << ")  ";
	}
}//end printInorder()

//Function purpose to print the postOrder traversal of tree
void printPostorder(TreeNode* tree) {

	if (tree != nullptr) {
		printPostorder(tree->left);
		printPostorder(tree->right);
		cout << tree->info << "\t";
	}
}//end printPostorder()

//Function purpose to print the preorder traversal of tree
void printPreorder(TreeNode* tree) {
	if (tree != nullptr) {
		cout << tree->info << "\t";
		printPreorder(tree->left);
		printPreorder(tree->right);
	}
}//end printPreorder()

//Helper function purpose to recursively search tree for item
void Retrive(TreeNode* tree, ItemType& item, bool& found) {
	if (tree == nullptr) found = false;
	else if (item < tree->info)Retrive(tree->left, item, found);
	else if (item > tree->info) Retrive(tree->right, item, found);
	else {
		item = tree->info;
		found = true;
	}
}//end retrive()


//Helper function purpose to delete all elements of tree
void Destroy(TreeNode*& tree) {
	if (tree != nullptr) {
		Destroy(tree->left);
		Destroy(tree->right);
		delete tree;
		tree = nullptr;
	}

}//end destroy()

//function purpose to insert items in tree
void Insert(TreeNode*& tree, ItemType item) {

	if (tree == nullptr) {

		tree = new TreeNode;
		tree->right = nullptr;
		tree->left = nullptr;
		tree->info = item;
	}
	else if (item < tree->info) Insert(tree->left, item);
	else Insert(tree->right, item);

}//end insert()

//Helper function purpose to delete item from a tree
void Delete(TreeNode*& tree, ItemType item) {
	if (item < tree->info)
		Delete(tree->left, item);
	else if (item > tree->info)
		Delete(tree->right, item);
	else
		DeleteNode(tree);

}

//Helper function purpose to delte node pointed by tree
void DeleteNode(TreeNode*& tree) {
	ItemType data;
	TreeNode* tempPtr;

	tempPtr = tree;
	if (tree->left == nullptr) {
		tree = tree->right;
		delete tempPtr;
	}
	else if (tree->right == nullptr) {
		tree = tree->left;
		delete tempPtr;

	}
	else {
		GetPredecessor(tree->left, data);
		tree->info = data;
		Delete(tree->left, data);
	}

}//end deleteNode()

//Helper function purpose sets data to the info member of the rightmost node tree
void GetPredecessor(TreeNode* tree, ItemType& data) {
	while (tree->right != nullptr)
	{
		tree = tree->right;
		data = tree->info;
	}
}//end getPredecesor()