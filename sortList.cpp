/*
Problem: Sort List
Method:  merge sort
Author: 'gq' 
*/
#include<iostream>
using namespace std;

struct ListNode{
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
       ListNode *sortList(ListNode *head) 
	   {
        if(!head)
			return NULL;
		int len=0;
		ListNode *p=head;
		while(p)
		{
			len++;
			p=p->next;
		}
		if(len==1)
			return head;
		//将链表分为两个链表
		int mid=len/2;
		ListNode *head1=head,*head2=head,*t;
		int i=0;
		while(i<mid)
		{
			t=head2;
			head2=head2->next;
			i++;
		}
		t->next=NULL;
		head1=sortList(head1);
		head2=sortList(head2);
		//merge head1,head2
		head=mergeTwoLists(head1,head2);
		return head;           
    }
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
             if(l1==NULL)
                 return l2;
             if(l2==NULL)
                 return l1;
             ListNode *res=new ListNode(0);
             ListNode *temp=res;
             while(l1&&l2)
             {
                 if(l1->val<=l2->val)
                 {
                    temp->next=l1;
                    l1=l1->next;
                    temp=temp->next;
                 }
                 else
                 {
                     temp->next=l2;
                     l2=l2->next;
                     temp=temp->next;
                 } 
             }
             if(l1==NULL)
             {
               temp->next=l2;
             }
             else
             {
                 temp->next=l1;
             }
             return res->next;        
    }
}; 
