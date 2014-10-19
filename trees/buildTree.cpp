/*
Problem: Construct Binary Tree from Preorder and Inorder Traversal    
Method:  recursion
Author: 'gq' 
*/
#include<iostream>
#include<cstdlib> 
#include<vector>
#include<algorithm>
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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        if(preorder.empty()||inorder.empty())
            return NULL;
        int len=preorder.size();
        return helper(preorder,inorder,0,len-1,0,len-1);
    }
    TreeNode *helper(vector<int> &preorder,vector<int> &inorder,int s1,int e1,int s2,int e2){
        if(e1<s1||e2<s2)
            return NULL;
        TreeNode *root=new TreeNode(preorder[s1]);
        int i=s2;
        for(;i<=e2;i++){
            if(preorder[s1]==inorder[i])
            break;
        }
        root->left=helper(preorder,inorder,s1+1,s1+i-s2,s2,i-1);
        root->right=helper(preorder,inorder,s1+i-s2+1,e1,i+1,e2);
        return root;
    }
};
