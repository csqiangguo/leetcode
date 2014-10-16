/*
Problem: Remove Duplicates from Sorted List II
Method: 
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
class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if(NULL==head)
            return head;
        ListNode *newHead=new ListNode(0);
        ListNode *p=head,*t=newHead;
        while(p)
        {
            int num=0;
            ListNode *q=p;
            while(q&&q->val==p->val){
                q=q->next;
                num++;
            }
            if(num==1){
                t->next=p;
                t=p;
            }
            p=q;
        }
        t->next=NULL;
        return newHead->next;
    }
};

