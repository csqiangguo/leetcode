/*
problem: Populating Next Right Pointers in Each Node
method: level tranversal
author: gq
*/
#include<iostream>
#include<string>
#include<queue>
using namespace std;


/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(NULL==root)
            return ;
        queue<TreeLinkNode*> q;
        q.push(root);
        while(!q.empty()){
            int levelNum=q.size();
            TreeLinkNode *pre=NULL;
            for(int i=0;i<levelNum;i++){
                TreeLinkNode *p=q.front();
                if(pre==NULL)
                    pre=p;
                else{
                    pre->next=p;
                    pre=pre->next;
                }
                if(p->left)
                    q.push(p->left);
                if(p->right)
                    q.push(p->right);
                q.pop();
            }
            pre->next=NULL;
        }
    }
};
