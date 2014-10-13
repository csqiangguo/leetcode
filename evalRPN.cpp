/*
Problem: Evaluate Reverse Polish Notation
Method:  stack 
Author: 'gq' 
*/
#include<iostream>
using namespace std;
class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        if(tokens.empty())
            return 0;
        stack<int> s;
        int op1=0,op2=0;
        for(int i=0;i<tokens.size();i++)
        {
            if(tokens[i]=="+")
            {
                op2=s.top();s.pop();op1=s.top();s.pop();s.push(op1+op2);
            }
            else if(tokens[i]=="-")
            {
                op2=s.top();s.pop();op1=s.top();s.pop();s.push(op1-op2);
            }
            else if(tokens[i]=="*")
            {
                op2=s.top();s.pop();op1=s.top();s.pop();s.push(op1*op2);
            }
            else if(tokens[i]=="/")
            {
                op2=s.top();s.pop();op1=s.top();s.pop();s.push(op1/op2);
            }
            else
                s.push(atoi(tokens[i].c_str()));
        }
        return s.top();
    }
};
