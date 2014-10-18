/*
Problem: Partition List
Method: 
Author: 'gq' 
*/
#include<iostream>
#include<string> 
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
    ListNode *partition(ListNode *head, int x) {
        if(NULL==head)
            return head;
        ListNode *lefthead=new ListNode(0),*left=lefthead;
        ListNode *righthead=new ListNode(0),*right=righthead;
        while(head){
            if(head->val<x){
                left->next=head;
                left=left->next;
            }
            else{
                right->next=head;
                right=right->next;
            }
            head=head->next;
        }
        left->next=righthead->next;
        right->next=NULL;
        return lefthead->next;
    }
};
