/*
Problem: Construct Binary Tree from Inorder and Postorder Traversal    
Method:  recursion
Author: 'gq' 
*/
#include<iostream>
#include<cstdlib> 
#include<algorithm>
#include<vector>
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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        if(postorder.empty()||inorder.empty())
            return NULL;
        int len=postorder.size();
        return helper(inorder,postorder,0,len-1,0,len-1);
    }
    TreeNode *helper(vector<int> &inorder,vector<int> &postorder,int s1,int e1,int s2,int e2){
        if(e1<s1||e2<s2)
            return NULL;
        TreeNode *root=new TreeNode(postorder[e2]);
        int i=s1;
        for(;i<=e1;i++){
            if(postorder[e2]==inorder[i])
            break;
        }
        root->left=helper(inorder,postorder,s1,i-1,s2,s2+i-s1-1);
        root->right=helper(inorder,postorder,i+1,e1,s2+i-s1,e2-1);
        return root;
    }
};
