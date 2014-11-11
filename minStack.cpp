/*
Problem: Min Stack 
Method:  trick 
Author: 'gq' 
*/
#include<iostream>
#include<cstdlib>
#include<string> 
#include<algorithm>
using namespace std;
class MinStack {
public:
    void push(int x) {
        data.push(x);
        if(mindata.empty()||mindata.top()>=x)
            mindata.push(x);
    }

    void pop() {
        if(mindata.top()==data.top())
            mindata.pop();
        data.pop();
    }

    int top() {
        return data.top();
    }

    int getMin() {
        return mindata.top();
    }
private:
    stack<int> data;
    stack<int> mindata;
};
class MinStack1 {
public:
    void push(int x) {
        if(s.empty()){
            min=x;
            s.push(0);
        }
        else{
            s.push(x-min);
            if(x<min)
                min=x;
        }
    }
    void pop() {
        if(s.empty())
            return ;
        int val=s.top();
        s.pop();
        if(val<0){
            min=min-val;
        }
    }

    int top() {
        if(s.top()<0)
            return min;
        else
            return s.top()+min;
    }

    int getMin() {
        return min;
    }
private:
    stack<long long> s;
    int min;
};
