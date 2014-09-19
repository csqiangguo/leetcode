/*
Problem: Reverse Nodes in k-Group
Method:  reverse  
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
    ListNode *reverseKGroup(ListNode *head, int k) {
    	ListNode *newhead=new ListNode(0);
    	newhead->next=head;
        ListNode *l=head,*pre=newhead;
    	while(l)
    	{
    		int j=0;
    		ListNode *p=l;
    		while(j<k&&p)
    		{
    			p=p->next;
    			j++;
    		}
    		if(j!=k)
    		{
    			return newhead->next;
    		}
        	p=l;
        	ListNode *first=l,*second=first->next;
        	l->next=NULL; 
        	int i=1;
        	while(i<k&&first&&second)
        	{
            	ListNode *third=second->next;
            	second->next=first;
            	first=second;
            	second=third;
            	i++;
        	}
        	pre->next=first;
        	l->next=second;
        	pre=l;
        	l=second;
    	}
    	return newhead->next;
    }
};
int main()
{
	ListNode *head=new ListNode(0);
	ListNode *h1=new ListNode(1);
	ListNode *h2=new ListNode(2);
	ListNode *h3=new ListNode(3);
	ListNode *h4=new ListNode(4);
	head->next=h1;
	h1->next=h2;
	h2->next=h3;
	h3->next=h4;
	Solution s;
	ListNode *res=s.reverseKGroup(head,2);
	while(res)
	{
		cout<<res->val<<' ';
		res=res->next;
	}
	cout<<endl;
	cin.get();
	return 0;
}
