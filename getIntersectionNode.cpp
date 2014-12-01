/*
Problem: Intersection of Two Linked Lists
Method: two pointers 
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA==NULL||headB==NULL)
            return NULL;
        ListNode *p1,*p2;
        p1=headA,p2=headB;
        int lenA=0,lenB=0;
        while(p1){
            lenA++;
            p1=p1->next;
        }
        while(p2){
            lenB++;
            p2=p2->next;
        }
        p1=headA,p2=headB;
        while(lenA<lenB){
            p2=p2->next;
            lenA++;
        }
        while(lenB<lenA){
            p1=p1->next;
            lenB++;
        }
        while(p1&&p2){
            if(p1==p2)
                return p1;
            p1=p1->next;
            p2=p2->next;
        }
        return false;
    }
};
