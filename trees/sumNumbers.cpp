/*
Problem: Sum Root to Leaf Numbers   
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
    int sumNumbers(TreeNode *root) {
        return helper(root,0);
    }
    int helper(TreeNode* root,int sum)
    {
        if(NULL==root)
            return 0;
        if(!root->left&&!root->right)
            return sum*10+root->val;
        return helper(root->left,sum*10+root->val)+helper(root->right,sum*10+root->val);
        
    }
};
