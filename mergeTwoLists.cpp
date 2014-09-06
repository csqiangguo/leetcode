/*
Problem: Merge Two Sorted Lists
Method: merge 
Author: 'gq' 
*/
#include<iostream>
#include<vector>
using namespace std;
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
class Solution {
public:
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
int main()
{
    cin.get();
    return 0;
}
