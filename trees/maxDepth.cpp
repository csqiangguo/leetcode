/*
Problem: Maximum Depth of Binary Tree  
Method:  recursion/Levelorder Traverse
Author: 'gq' 
*/
#include<iostream>
#include<cstdlib> 
#include<algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
//recursion
class Solution{
public:
    int maxDepth(TreeNode* root){
        if(root==NULL)
        	return 0;
        int leftDepth=maxDepth(root->left);
        int rightDepth=maxDepth(root->right);
        return leftDepth<rightDepth?rightDepth+1:leftDepth+1; 
    }
};
//leveOrder traverse
class Solution1{
public:
    int maxDepth(TreeNode* root){
        if(root==NULL)
            return 0;
        int leftDepth=maxDepth(root->left);
        int rightDepth=maxDepth(root->right);
        return leftDepth>rightDepth?leftDepth+1:rightDepth+1;
    }
};
int main()
{
	cin.get();
	return 0;
}
