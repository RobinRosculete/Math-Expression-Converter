#ifndef TREEHELPER_H
#define TREEHELPER_H
#include "TreeNode.h"
//Helper functions
void printInorder(TreeNode* tree);
void printPostorder(TreeNode* tree);
void printPreorder(TreeNode* tree);
void Retrive(TreeNode* tree, ItemType& item, bool& fount);
void Destroy(TreeNode*& tree);
void Insert(TreeNode*& tree, ItemType item);
void CopyTree(TreeNode*& copy, const TreeNode* originalTree);
void GetPredecessor(TreeNode* tree, ItemType& data);
void DeleteNode(TreeNode*& tree);
void Delete(TreeNode*& tree, ItemType data);


#endif 
