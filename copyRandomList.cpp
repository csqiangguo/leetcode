/*
Problem: Copy List with Random Pointer 
Method:   hash+tranversal 2 bian
Author: 'gq' 
*/
#include<iostream>
#include<map>
using namespace std;

 struct RandomListNode {
      int label;
      RandomListNode *next, *random;
      RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
  };

class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(NULL==head)
            return NULL;
        map<RandomListNode *, RandomListNode*> mp1,mp2;
        RandomListNode *newHead=new RandomListNode(0);
        RandomListNode *pre=newHead,*p=head;
        while(p){
            
            RandomListNode *q=new RandomListNode(p->label);
            pre->next=q;
            mp1[p]=q;
            if(p->random){
                mp2[q]=p->random;
            }
            pre=pre->next;
            p=p->next;
        }
        map<RandomListNode *, RandomListNode*>::iterator iter=mp2.begin();
        for(;iter!=mp2.end();iter++){
            iter->first->random=mp1[iter->second];
        }
        return newHead->next;
    }
};
class Solution1 {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(NULL==head)
            return NULL;
        map<RandomListNode *, RandomListNode*> mp;
        RandomListNode *newHead=new RandomListNode(0);
        RandomListNode *pre=newHead,*p=head;
        while(p){
            
            RandomListNode *q=new RandomListNode(p->label);
            pre->next=q;
            mp[p]=q;
            pre=pre->next;
            p=p->next;
        }
        p=head;
        while(p){
            if(p->random)
                mp[p]->random=mp[p->random];
                p=p->next;
        }
        return newHead->next;
    }
};
int main()
{
    RandomListNode *p=new RandomListNode(-1);
    p->next=new RandomListNode(-1);
    Solution s;
    RandomListNode *head=s.copyRandomList(p);
    while(head){
	cout<<head->label<<' ';
	head=head->next;
    }
	cout<<endl;
	return 0;
}
