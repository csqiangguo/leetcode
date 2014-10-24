/*
Problem: Longest Valid Parentheses 
Method:  stack
Author: 'gq' 
*/
#include<iostream>
using namespace std;
class Solution {
public:
    int longestValidParentheses(string s) {
        if(s.empty())
            return 0;
        stack<int> st;
        int max=0;
        int i=0;
        while(i<s.length()){
            if(s[i]=='(')
                st.push(i);
            else{
                if(!st.empty()&&s[st.top()]=='('){
                    st.pop();
                }
                else{
                    st.push(i);
                }
            }
            i++;
        }
        st.push(s.length());
        while(!st.empty()){
            int right=st.top();
            st.pop();
            int left=-1;
            if(!st.empty()){
                left=st.top();
            }
            if(max<right-left-1)
                max=right-left-1;
        }
        return max;
    }
};
