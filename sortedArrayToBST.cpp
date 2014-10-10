/*
Problem: Convert Sorted Array to Binary Search Tree 
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
    TreeNode *sortedArrayToBST(vector<int> &num) {
        TreeNode *res=NULL;
        res=helper(num,0,num.size()-1);
        return res;
    }
    TreeNode *helper(vector<int> &num,int left,int right)
    {
        if(right<left)
            return NULL;
        int mid=(left+right)/2;
        TreeNode *lnode=helper(num,left,mid-1);
        TreeNode *rnode=helper(num,mid+1,right);
        TreeNode *root=new TreeNode(num[mid]);
        root->left=lnode;
        root->right=rnode;
        return root;
    }
};
