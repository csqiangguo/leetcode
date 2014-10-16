/*
Problem: Remove Duplicates from Sorted List
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
        ListNode *p=head,*q=head->next;
        while(q)
        {
            if(q->val!=p->val){
                p->next=q;
                p=q;
            }
            q=q->next;
        }
        p->next=NULL;
        return head;
    }
};
