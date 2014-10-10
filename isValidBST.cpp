/*
Problem: Validate Binary Search Tree 
Method:  recursion 
Author: 'gq' 
*/
#include<iostream>
using namespace std;
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isValidBST(TreeNode *root) {
        return helper(root,INT_MIN,INT_MAX);
    }
    bool helper(TreeNode *root,int min,int max)
    {
        if(!root)
            return  true;
        if(root->val<=min||max<=root->val)
            return false;
        return helper(root->left,min,root->val)&&helper(root->right,root->val,max);
    }
};
