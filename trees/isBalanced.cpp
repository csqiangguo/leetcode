/*
Problem: Balanced Binary Tree  
Method:  recursion
Author: 'gq' 
*/
#include<iostream>
#include<cstdlib> 
#include<algorithm>
using namespace std;

class Solution {
public:
    bool isBalanced(TreeNode *root) {
        if(NULL==root)
			return true;
		return getDepth(root)>=0; 
    }
    int getDepth(TreeNode* root)
    {
    	if(NULL==root)
    		return 0;
    	int left=getDepth(root->left);
    	int right=getDepth(root->right);
    	if(left<0||right<0)
    		return -1;
    	if(abs(left-right)>=2)
    		return -1;
    	return left<right?right+1:left+1;
    }
    
};
