/*
Problem: Reverse Linked List II
Method:  
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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        if(head==NULL||n<=m)
            return head;
        ListNode *newHead=new ListNode(0);
        newHead->next=head;
        ListNode *pre=newHead,*p=pre,*q=head;
        int num=0;
        while(p){
            if(num+1==m){
                pre=p;
            }
            if(num==n){
                q=p->next;
                break;
            }
            num++;
            p=p->next;
        }
        ListNode * t=reverse(pre->next,q);
        pre->next=t;
        return newHead->next;
    }
    ListNode *reverse(ListNode *begin,ListNode *end){
        ListNode *p=begin,*q=p->next;
        while(q!=end){
            ListNode *r=q->next;
            q->next=p;
            p=q;
            q=r;
        }
        begin->next=end;
        return p;
    }
};
int main(){
	ListNode *head=new ListNode(3);
	head->next=new ListNode(5);
	Solution s;
	ListNode *p=s.reverseBetween(head,1,2);
	while(p){
		cout<<p->val<<endl;
		p=p->next;
	}
	cin.get();
	return 0;
} 
