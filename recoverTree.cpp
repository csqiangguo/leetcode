/*
Problem: Recover Binary Search Tree 
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
    void recoverTree(TreeNode *root) {
        if(!root)
            return;
        TreeNode *pre=NULL;
        TreeNode *res=NULL;
        TreeNode *visited=NULL;
        helper(root,visited,pre,res);
        int temp=pre->val;
        pre->val=res->val;
        res->val=temp;
    }
    void helper(TreeNode *root,TreeNode *&visited,TreeNode *&pre,TreeNode *&res)
    {
        if(!root)
        {
            return;
        }
        helper(root->left,visited,pre,res);
        if(visited)
        {
            if(root->val<visited->val)
            {
                if(pre==NULL)
                {
                    pre=visited;
                    res=root;
                }
                else
                    res=root;
            }
        }
        visited=root;
        helper(root->right,visited,pre,res);
    }
};
