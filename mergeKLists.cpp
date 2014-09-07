/*
Problem: Merge k sorted lists
Method:  merge sort
Author: 'gq' 
*/
#include<iostream>
#include<vector>
using namespace std;

struct ListNode{
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists){
             if(lists.empty())
                return NULL;
             if(lists.size()==1)
                return lists[0];
             vector<ListNode*> lhaf,rhaf;
             int mid=lists.size()/2;
             for(int i=0;i<mid;i++)
                lhaf.push_back(lists[i]);
             for(int j=mid;j<lists.size();j++)
                rhaf.push_back(lists[j]);
             ListNode *lhead=mergeKLists(lhaf);
             ListNode *rhead=mergeKLists(rhaf);
             ListNode *head=mergeTwoLists(lhead,rhead);
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
