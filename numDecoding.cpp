/*
Problem: Decode Ways  
Method:  recursion 
Author: 'gq' 
*/
#include<iostream>
#include<cstdlib>
#include<string> 
#include<algorithm>
using namespace std;
class Solution {
public:
    int numDecodings(string s) {
        if(s.size()==0||s[0]=='0')
        	return 0;
        if(s.size()==1)
        	return 1;
        if(s.size()==2)
        {
        	if(s[1]=='0')
        	{
        		if(s[0]=='1'||s[0]=='2')
        			return 1;
        		else
        			return 0;
        	}
        	int num=(s[0]-'0')*10+s[1]-'0';
        	if(11<=num&&num<=26)
        		return 2;
        	else
        		return 1;
        }
        string res;
        res+=s[0];
        int f1=numDecodings(res);
        res+=s[1];
        int f2=numDecodings(res);
        int f3=0;
        for(int i=2;i<s.size();i++)
        {
        	string one,two;
        	one+=s[i];
        	two+=s[i-1];
        	two+=s[i];
        	f3=num2one(one)*f2+num2one(two)*f1;
        	f1=f2;
        	f2=f3;
        }
        return f3;
    }
    int num2one(string s)
    {
    	if(s.size()==1)
		{
			if(s[0]=='0')
				return 0;
			else
				return 1;
		} 
		if(s.size()==2)
		{
	    	if(s[0]=='0')
	    		return 0;
	    	if(s[1]=='0')
	    	{
	    		if(s[0]=='1'||s[0]=='2')
	        		return 1;
	        	else
	        		return 0;
	    	}
	    	int num=(s[0]-'0')*10+s[1]-'0';
	        if(11<=num&&num<=26)
	        	return 1;
	        else
	        	return 0;
		}
		return 0;
    }
};
int main()
{
	string str="5114";
	Solution s;
	cout<<s.numDecodings(str)<<endl;
	cin.get();
	return 0;
}
