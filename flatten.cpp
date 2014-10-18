/*
Problem: Flatten Binary Tree to Linked List
Method:  
Author: 'gq' 
*/
#include<iostream>
#include<string> 
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
    void flatten(TreeNode *root) {
        if(NULL==root)
            return ;
        flatten(root->left);
        flatten(root->right);
        TreeNode *p=root->left;
        if(p){
            while(p->right){
                p=p->right;
            }
        }
        TreeNode *q=root->right;
        if(root->left){
            root->right=root->left;
            root->left=NULL;
        }
        if(p)
            p->right=q;
    }
};
