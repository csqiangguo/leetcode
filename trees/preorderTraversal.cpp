/*
Problem: Binary Tree Preorder Traversal   
Method:  recursion/preorder Traverse
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
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> res;
        if(!root)
        	return res;
        res.push_back(root->val);
        vector<int> l=preorderTraversal(root->left);
        res.insert(res.end(),l.begin(),l.end());
        vector<int> r=preorderTraversal(root->right);
        res.insert(res.end(),r.begin(),r.end());
    }
};
//leveOrder traverse
class Solution1{
public:
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> res;
        stack<TreeNode*> s;
        while(root||!s.empty())
		{
			if(root)
			{
				res.push_back(root->val);
				s.push(root);
				root=root->left;
			}
			else
			{
				root=s.top();
				s.pop();
				root=root->right;
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
	Solution1 s;
	res=s.preorderTraversal(root);
	for(int i=0;i<res.size();i++)
	{
		cout<<res[i]<<endl;
	}
	cout<<endl;
	cin.get();
	return 0;
}
