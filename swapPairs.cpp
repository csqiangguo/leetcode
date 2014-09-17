/*
Problem: Swap Nodes in Pairs 
Method: swap 
Author: 'gq' 
*/
#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        if(NULL==head||NULL==head->next)
            return head;
        ListNode *headNode=new ListNode(0);
        headNode->next=head;
        ListNode *pPre=headNode;
        ListNode *pre=head,*p=pre->next;
        while(pre&&p)
        {
            ListNode *nex=p->next;
            pPre->next=p;
            p->next=pre;
            pre->next=nex;
            pPre=pre;
            pre=nex;
            if(!pre)
                break;
            p=nex->next;
        }
        return headNode->next;
    }
};
