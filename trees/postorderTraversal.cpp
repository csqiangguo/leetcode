/*
Problem: Binary Tree Postorder Traversal  
Method:  recursion/post order Traversal
Author: 'gq' 
*/
#include<iostream>
#include<cstdlib> 
#include<vector>
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
//leveOrder traverse
class Solution1{
public:
    int maxDepth(TreeNode* root){
        if(root==NULL)
            return 0;
        int leftDepth=maxDepth(root->left);
        int rightDepth=maxDepth(root->right);
        return leftDepth>rightDepth?leftDepth+1:rightDepth+1;
    }
};
int main()
{
	vector<int> res;
	if(res.begin()==res.end())
		cout<<"yes"<<endl;
	cin.get();
	return 0;
}
