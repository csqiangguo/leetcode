/*
Problem: Valid Parentheses  
Method:  recursion/Levelorder Traverse
Author: 'gq' 
*/
#include<iostream>
#include<cstdlib> 
#include<string>
#include<stack>
#include<algorithm>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        if(s.size()==0)
        	return true;  
    	stack<char> st; 
    	for(int i=0;i<s.size();i++)  
    	{  
        	switch(s[i])  
        	{  
            	case '(':  
           	 	case '{':  
            	case '[':  
                	st.push(s[i]);  
                	break;  
            	case ')':  
                	if(st.empty() || st.top()!='(')  
                    	return false;
					else
						st.pop();  
                	break;  
            	case '}':  
                	if(st.empty() || st.top()!='{')  
                    	return false; 
					else
						st.pop(); 
                	break;  
            	case ']':  
                	if(st.empty() || st.top()!='[')  
                    	return false; 
					else
						st.pop(); 
                	break;   
            	default:  
                	break;  
        }  
    }  
    if(st.empty())  
        return true;  
    return false;
    }
};
int main()
{
	string str="((({[])))";
	Solution s;
	if(s.isValid(str))
		cout<<"yes"<<endl;
	else
		cout<<"no"<<endl;
	cin.get();
	return 0;
}
