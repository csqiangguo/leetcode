/*
Problem: Binary Tree Level Order Traversal  
Method:  recursion/Levelorder Traverse
Author: 'gq' 
*/
#include<iostream>
#include<cstdlib> 
#include<vector>
#include<queue>
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
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int>> res;
        if(root==NULL)
            return res;
        int depth=getDepth(root);
        for(int i=0;i<depth;i++)
        {
            vector<int> temp=getLevel(root,i);
            if(!temp.empty())
                res.push_back(temp);
        }
        return res;
    }
private:
    int getDepth(TreeNode *root)
    {
        if(!root)
            return 0;
        int ldepth=getDepth(root->left);
        int rdepth=getDepth(root->right);
        return ldepth<rdepth?rdepth+1:ldepth+1;
    }
    vector<int> getLevel(TreeNode *root,int level)
    {
        vector<int> res;
        if(!root)
            return res;
        if(level==0)
        {
            res.push_back(root->val);
            return res;
        }
        vector<int> l=getLevel(root->left,level-1);
        res.insert(res.end(),l.begin(),l.end());
        vector<int> r=getLevel(root->right,level-1);
        res.insert(res.end(),r.begin(),r.end());
        return res;
    }
};
//leveOrder traverse
class Solution1{
public:
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int>> res;
        if(root==NULL)
            return res;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
        	int cur=0;
        	int levelNum=q.size();
        	vector<int> temp;
        	while(cur<levelNum)
        	{
        		temp.push_back(q.front()->val);
        		if(q.front()->left)
        			q.push(q.front()->left);
        		if(q.front()->right)
        			q.push(q.front()->right);
        		q.pop();
        		cur++;
        	}
        	res.push_back(temp);
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
	vector<vector<int>> res;
	Solution1 s;
	res=s.levelOrder(root);
	for(int i=0;i<res.size();i++)
	{
		for(int j=0;j<res[i].size();j++)
		{
			cout<<res[i][j]<<' ';
		}
		cout<<endl;
	}
	cin.get();
	return 0;
}
