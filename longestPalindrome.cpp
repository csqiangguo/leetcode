/*
Problem: Longest Palindromic Substring  
Method:   
Author: 'gq' 
*/
#include<iostream>
using namespace std;
class Solution {
public:
    string longestPalindrome(string s) {
        if(s.empty()||s.size()==1)
            return s;
        int maxLen=1;
        string res;
        res+=s[0];
        for(int i=0;i<s.size();i++)
        {
            int j=i-1,k=i+1;
            while(0<=j&&k<s.size())
            {
                if(s[j]!=s[k])
                    break;
                j--;
                k++;
            }
            if(maxLen<k-j-1)
            {
                maxLen=k-j-1;
                res=s.substr(j+1,maxLen);
            }
            if(s[i]==s[i+1])
            {
                int j=i-1,k=i+2;
                while(0<=j&&k<s.size())
                {
                    if(s[j]!=s[k])
                        break;
                    j--;
                    k++;
                }
                if(maxLen<k-j-1)
                {
                    maxLen=k-j-1;
                    res=s.substr(j+1,maxLen);
                }
            }
        }
        return res;
    }
};
