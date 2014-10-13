/*
Problem: Valid Number 
Method:   
Author: 'gq' 
*/
#include<iostream>
using namespace std;
class Solution {
public:
    bool isNumber(const char *s) {
        int i=0;
        for(;s[i]==' ';i++);
        if(s[i]=='+'||s[i]=='-')
            i++;
        int np=0,nd=0;
        for(;('0'<=s[i]&&s[i]<='9')||s[i]=='.';i++)
        {
            if(s[i]=='.')
                np++;
            else
                nd++;
        }
        if(1<np||nd<1)
            return false;
        if(s[i]=='e')
        {
            i++;
            if(s[i]=='+'||s[i]=='-')
                i++;
            int digit=0;
            for(;'0'<=s[i]&&s[i]<='9';i++)
                digit++;
            if(digit<1)
                return false;
        }
        for(;s[i]==' ';i++);
        return s[i]=='\0';
    }
};
