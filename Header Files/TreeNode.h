#ifndef TREENODE_H
#define TREENODE_H
#include<iostream>
typedef char ItemType;
using namespace std;

struct TreeNode {
	ItemType info;
	TreeNode* left;
	TreeNode* right;
};
#endif 