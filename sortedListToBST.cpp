/*
Problem: Convert Sorted List to Binary Search Tree 
Method:  recursion 
Author: 'gq' 
*/
#include<iostream>
using namespace std;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head) {
        if(NULL==head)
            return NULL;
        int count=0;
        ListNode *p=head;
        while(p)
        {
            count++;
            p=p->next;
        }
        TreeNode *res=NULL;
        res=helper(head,0,count-1);
        return res;
    }
    TreeNode *helper(ListNode *&head,int left,int right)
    {
        if(right<left)
            return NULL;
        int mid=(left+right)/2;
        TreeNode *lnode=helper(head,left,mid-1);
        TreeNode *root=new TreeNode(head->val);
        head=head->next;
        TreeNode *rnode=helper(head,mid+1,right);
        root->left=lnode;
        root->right=rnode;
        return root;
    }
};
