/*
Problem: Valid Palindrome 
Method:  Palindrome 
Author: 'gq' 
*/
#include<iostream>
using namespace std;
class Solution {
public:
    bool isPalindrome(string s) {
        if(s.empty())
            return true;
        string newStr;
        for(int i=0;i<s.size();i++)
        {
            if(isalnum(s[i]))
                newStr+=tolower(s[i]);
        }
        int i=0,j=newStr.size()-1;
        while(i<j)
        {
            if(newStr[i]!=newStr[j])
                return false;
            i++;
            j--;
        }
        return j<=i;
    }
};
