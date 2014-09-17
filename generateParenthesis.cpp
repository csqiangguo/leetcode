/*
Problem: Generate Parentheses
Method: dynamic  programming
Author: 'gq' 
*/
#include<iostream>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        if(n<=0)
            return res;
        string s;
        helper(n,n,s,res);
        return res;
    }
    void helper(int left,int right,string s,vector<string>& res)
    {
        if(left==0&&right==0)
            res.push_back(s);
        if(left>0)
        {
            helper(left-1,right,s+'(',res);
        }
        if(right>0&&left<right)
        {
            helper(left,right-1,s+')',res);
        }
    }
};
int main()
{
	cin.get();
	return 0;
} 
