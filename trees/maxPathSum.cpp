/*
Problem: Binary Tree Maximum Path Sum   
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
    int maxPathSum(TreeNode *root) {
        if(NULL==root)
            return 0;
        if(!root->left&&!root->right)
            return root->val;
		int max=root->val;
		helper(root,max);
        return max;
    }
	int helper(TreeNode* root,int &max)
	{
		if(NULL==root)
			return 0;
		if(!root->left&&!root->right)
		{
			if(max<root->val)
				max=root->val;
			return root->val;
		}
		if(max<root->val)
			max=root->val;
		int crossMax=root->val;
		if(!root->left)
		{
			int right=helper(root->right,max);
			if(max<right)
				max=right;
			if(max<right+root->val)
				max=right+root->val;
			if(crossMax<right+root->val)
				crossMax=right+root->val;
			return crossMax;
		}
		if(!root->right)
		{
			int left=helper(root->left,max);
			if(max<left)
				max=left;
			if(max<left+root->val)
				max=left+root->val;
			if(crossMax<left+root->val)
				crossMax=left+root->val;
			return crossMax;
		}
		int right=helper(root->right,max);
		int left=helper(root->left,max);
		if(max<left)
			max=left;
		if(max<right)
			max=right;
		if(max<right+root->val)
			max=right+root->val;
		if(max<left+root->val)
			max=left+root->val;
		if(max<left+right+root->val)
			max=left+right+root->val;
		if(crossMax<right+root->val)
			crossMax=right+root->val;
		if(crossMax<left+root->val)
			crossMax=left+root->val;
		return crossMax;
	}
};
int main()
{
	TreeNode *root=new TreeNode(-2);
	TreeNode *l=new TreeNode(1);
	TreeNode *r=new TreeNode(-3);
	TreeNode *ll=new TreeNode(1);
	TreeNode *lr=new TreeNode(3);
	TreeNode *rl=new TreeNode(-2);
	TreeNode *lll=new TreeNode(-1);
	root->left=l;
	root->right=r;
	root->left->left=ll;
	root->left->right=lr;
	root->right->left=rl;
	root->left->left->left=lll;
	Solution s;
	cout<<s.maxPathSum(root)<<endl;
	cin.get();
	return 0;
}
