/*
Problem: Multiply Strings 
Method:  carry 
Author: 'gq' 
*/
#include<iostream>
#include<cstdlib>
#include<string> 
#include<algorithm>
using namespace std;
class Solution {
public:
    string multiply(string num1, string num2) {
        string res;
        if(num1=="0"||num2=="0")
        {
            res+="0";
            return res;
        }
        int pos=0;
        int len1=num1.size();
        int len2=num2.size();
		for(int i=0;i<len1+len2;i++)
			res+='0';
        for(int i=0;i<len1;i++)
        {
        	for(int j=0;j<len2;j++)
        	{
        		pos=i+j;
        		int mul=(num2[len2-j-1]-'0')*(num1[len1-i-1]-'0')+res[pos]-'0';
            	res[pos + 1] += mul / 10;
				res[pos] = mul % 10+'0';
        	}
        }
        while(res.back()=='0') 
        	res.pop_back();
        reverse(res.begin(),res.end());
        return res;
    }
};
int main()
{
	string str1="1";
	string str2="1";
	Solution s;
	cout<<s.multiply(str1,str2)<<endl;
	cin.get();
	return 0;
}
