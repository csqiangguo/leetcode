/*
Problem: Remove Nth Node From End of List
Method:  fast and slow pointers
Author: 'gq' 
*/
#include<iostream>
#include<cstdlib> 
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
 
 class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        if(NULL==head)
            return NULL;
        ListNode *first=head,*second=head,*pre=head;
        int i=0;
        while(i<n-1)
        {
            first=first->next;
            if(NULL==first)
                return NULL;
            i++;
        }
        while(first->next!=NULL)
        {
            pre=second;
            second=second->next;
            first=first->next;
        }
        if(pre==second)
        {
            head=second->next;
            delete second;
            return head;
        }
        pre->next=second->next;
        delete second;
        return head;
    }
};
int main()
{
	ListNode* head=new ListNode(1);
	head->next=new ListNode(2);
	head->next->next=new ListNode(3);
	ListNode* p=head->next->next;
	p->next=new ListNode(4);
	p->next->next=new ListNode(5);
	Solution s;
	head=s.removeNthFromEnd(head,2);
	while(head)
	{
		cout<<head->val<<' ';
		head=head->next;
		
	}
	cout<<endl;
	cin.get();
	return 0;
} 
