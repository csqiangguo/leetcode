/*
Problem: Unique Binary Search Trees II 
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
    vector<TreeNode *> generateTrees(int n) {
        vector<TreeNode *> res=helper(1,n);
        return res;
    }
    vector<TreeNode *> helper(int left,int right)
    {
        vector<TreeNode *> res;
        if(right<left)
        {
            res.push_back(NULL);
            return res;
        }
        for(int i=left;i<=right;i++)
        {
            vector<TreeNode *> lvec=helper(left,i-1);
            vector<TreeNode *> rvec=helper(i+1,right);
            for(int m=0;m<lvec.size();m++)
            {
                for(int n=0;n<rvec.size();n++)
                {
                    TreeNode *node=new TreeNode(i);
                    node->left=lvec[m];
                    node->right=rvec[n];
                    res.push_back(node);
                }
            }
        }
        return res;
    }
};
