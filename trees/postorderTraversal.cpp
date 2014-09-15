/*
Problem: Binary Tree Postorder Traversal  
Method:  recursion/post order Traversal
Author: 'gq' 
*/
#include<iostream>
#include<cstdlib> 
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
//recursion
class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> res;
        if(root==NULL)
            return res;
        vector<int> left=postorderTraversal(root->left);
        vector<int> right=postorderTraversal(root->right);
        vector<int>::iterator it=res.end();
        res.insert(it,left.begin(),left.end());
        it=res.end();
        res.insert(it,right.begin(),right.end());
        res.push_back(root->val);
    }
};
//postorder Traversal 1 按<根、右子树、左子树>遍历，然后逆序 
class Solution1{
public:
	vector<int> postorderTraversal(TreeNode *root) {
    	vector<int> res;
        stack<TreeNode*> s;
        while(root||!s.empty())
		{
			if(root)
			{
				res.push_back(root->val);
				s.push(root);
				root=root->right;
			}
			else
			{
				root=s.top();
				s.pop();
				root=root->left;
			}
		} 
        reverse(res.begin(),res.end());
        return res; 
    }
};
//
class Solution2{
public:
	vector<int> postorderTraversal(TreeNode *root) {
    	vector<int> res;
        stack<TreeNode*> s;
        TreeNode* pre=NULL; 
        while(root||!s.empty())
		{
			if(root)
			{
				s.push(root);
				root=root->left;
			}
			else if(s.top()->right!=pre)
			{
				root=s.top()->right;
				pre=NULL;
			}
			else
			{		
				res.push_back(s.top()->val);
				pre=s.top();
				s.pop();
			}
		} 
        return res; 
    }
};
int main()
{
	TreeNode *root=new TreeNode(1);
	TreeNode *l=new TreeNode(2);
	TreeNode *r=new TreeNode(3);
	TreeNode *ll=new TreeNode(4);
	root->left=l;
	root->right=r;
	root->left->left=ll;
	vector<int> res;
	Solution2 s;
	res=s.postorderTraversal(root);
	for(int i=0;i<res.size();i++)
	{
		cout<<res[i]<<endl;
	}
	cout<<endl;
	cin.get();
	return 0;
}
