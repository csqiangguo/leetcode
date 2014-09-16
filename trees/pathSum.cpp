/*
Problem: Path Sum II    
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
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<vector<int>> res;
        
        if(NULL==root)
            return res;
        if(sum==root->val&&!root->left&&!root->right)
        {
            vector<int> temp;
            temp.push_back(root->val);
            res.push_back(temp);
            return res;
        }
        vector<vector<int>> left=pathSum(root->left,sum-root->val);
        for(int i=0;i<left.size();i++)
        {
            vector<int> t;
            t.push_back(root->val);
            t.insert(t.end(),left[i].begin(),left[i].end());
            res.push_back(t);
        }
        vector<vector<int>> right=pathSum(root->right,sum-root->val);
        for(int i=0;i<right.size();i++)
        {
            vector<int> t;
            t.push_back(root->val);
            t.insert(t.end(),right[i].begin(),right[i].end());
            res.push_back(t);
        }
    }
};
