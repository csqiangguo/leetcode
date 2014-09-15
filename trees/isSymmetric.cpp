/*
Problem: Symmetric Tree   
Method:  level traversal
Author: 'gq' 
*/
#include<iostream>
#include<cstdlib> 
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
 struct TreeNode {
    int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 struct node{
 	int val;
 	int index;
 };
class Solution {
public:
    bool isSymmetric(TreeNode *root) {
        if(root==NULL)
            return true;
        queue<TreeNode*> q;
        queue<int> p;
        q.push(root);
        p.push(1);
        int i=1;
        while(!q.empty())
        {
        	int cur=0;
        	int levelNum=q.size();
        	vector<node> temp;
        	while(cur<levelNum)
        	{
        		node t;
        		t.val=q.front()->val;
        		t.index=p.front();
        		temp.push_back(t);
        		if(q.front()->left)
        		{
        			q.push(q.front()->left);
        			p.push(p.front()*2);
        		}
        		if(q.front()->right)
        		{
        			q.push(q.front()->right);
        			p.push(p.front()*2+1);
        		}
        		q.pop();
        		p.pop();
        		cur++;
        	}
        	if(!isSymmetricLevel(temp,i))
        		return false;
        	i=2*i;
        }
        return true;
    }
    bool isSymmetricLevel(vector<node> temp,int begin)
    {
    	if(begin==1)
    		return true;
    	if(temp.size()%2==1)
    		return false;
    	int i=0,j=temp.size()-1;
    	while(i<j)
    	{
    		if(temp[i].val!=temp[j].val)
    			return false;
    		if((temp[i].index+temp[j].index)!=(3*begin-1))
    			return false;
    		i++;
    		j--;
    	}
    	return true;
    }
};
int main()
{
	TreeNode *root=new TreeNode(1);
	TreeNode *l=new TreeNode(2);
	TreeNode *r=new TreeNode(2);
	TreeNode *ll=new TreeNode(4);
	TreeNode *rr=new TreeNode(4);
	root->left=l;
	root->right=r;
	root->left->left=ll;
	root->right->left=rr;
	Solution s;
	if(s.isSymmetric(root))
		cout<<"yes"<<endl;
	else
		cout<<"no"<<endl;
	cin.get();
	return 0;
}
