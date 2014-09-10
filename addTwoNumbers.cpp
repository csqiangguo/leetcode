/*
Problem: Add Binary 
Method:  string 
Author: 'gq' 
*/
#include<iostream>
#include<cstdlib>
#include<string> 
#include<algorithm>
using namespace std;
struct ListNode {
   int val;
   ListNode *next;
   ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
             if(l1==NULL)
                return l1;
             if(l2==NULL)
                return l1;
            int carry=0,digit=0;
            ListNode *head=new ListNode(0);
            ListNode *p=head;
             while(l1&&l2)
             {
                  int sum=l1->val+l2->val+carry;
                  digit=sum%10;
                  carry=sum/10;
                  ListNode *q=new ListNode(digit);
                  p->next=q;
                  p=q;
                  l1=l1->next;
                  l2=l2->next;
             }
             while(l1)
             {
                  int sum=l1->val+carry;
                  digit=sum%10;
                  carry=sum/10;
                  ListNode *q=new ListNode(digit);
                  p->next=q;
                  p=q;
                  l1=l1->next;
            }
             while(l2)
             {
                  int sum=l2->val+carry;
                  digit=sum%10;
                  carry=sum/10;
                  ListNode *q=new ListNode(digit);
                  p->next=q;
                  p=q;
                  l2=l2->next;
            }
            if(carry==1)
            {
               ListNode *q=new ListNode(carry);
               p->next=q;
            }
            return head->next;       
    }
};
int main()
{
   ListNode *l1=new ListNode(1);
   ListNode *l2=new ListNode(9);
   l1->next=new ListNode(9);
   Solution s;
   ListNode *res=s.addTwoNumbers(l1,l2);
   cout<<res->val<<endl;
   cout<<res->next->val<<endl;
   cout<<res->next->next->val<<endl;
   cin.get();
   return 0;
}
