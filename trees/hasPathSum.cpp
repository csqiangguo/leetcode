/*
Problem: Path Sum   
Method:  recursion
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
class Solution {
public:
    bool hasPathSum(TreeNode *root, int sum) {
        if(NULL==root)
            return false;
        if(root->left==NULL&&root->right==NULL&&sum==root->val)
            return true;
        return hasPathSum(root->left,sum-root->val)||hasPathSum(root->right,sum-root->val);   
    }
};
