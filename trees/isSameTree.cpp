/*
Problem: Binary Tree Inorder Traversal   
Method:  recursion/inlorder Traverse
Author: 'gq' 
*/
#include<iostream>
#include<cstdlib> 
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
//recursion
class Solution {
public:
    bool isSameTree(TreeNode *p, TreeNode *q) {
        if(NULL==p&&NULL==q)
            return true;
        if(NULL==p||NULL==q)
            return false;
        if(p->val!=q->val)
            return false;
        return isSameTree(p->left,q->left)&&isSameTree(p->right,q->right);
    }
};
