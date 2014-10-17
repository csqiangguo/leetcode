/*
Problem: Rotate List 
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
    ListNode *rotateRight(ListNode *head, int k) {
        if(NULL==head||k==0)
            return head;
        int len=0;
        ListNode *p=head;
        while(p){
            len++;
            p=p->next;
        }
        k=k%len;
        if(k==0)
            return head;
        ListNode *pre=head;
        p=head;
        int i=0;
        while(i<len-k){
            pre=p;
            p=p->next;
            i++;
        }
        pre->next=NULL;
        ListNode *newhead=p;
        while(p->next){
            p=p->next;
        }
        p->next=head;
        return newhead;
    }
};
