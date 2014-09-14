/*
Problem: Binary Tree Inorder Traversal   
Method:  recursion/inlorder Traverse
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
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> res;
        if(!root)
        	return res;
        vector<int> l=inorderTraversal(root->left);
        res.insert(res.end(),l.begin(),l.end());
        res.push_back(root->val);
        vector<int> r=inorderTraversal(root->right);
        res.insert(res.end(),r.begin(),r.end());
        return res;
    }
};
//inOrder traverse
class Solution1 {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> res;
        stack<TreeNode*> s;
        while(root||!s.empty())
        {
        	if(root)
        	{
        		s.push(root);
        		root=root->left;
        	}
        	else
        	{
        		root=s.top();
        		s.pop();
        		res.push_back(root->val);
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
	res=s.inorderTraversal(root);
	for(int i=0;i<res.size();i++)
	{
		cout<<res[i]<<endl;
	}
	cout<<endl;
	cin.get();
	return 0;
}
