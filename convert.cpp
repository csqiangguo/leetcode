/**
problem: ZigZag Conversion
author: gq
**/
#incude<iostream>
#include<string>
using namespace std;
class Solution {
public:
    string convert(string s, int nRows) {
        if(s.empty()||nRows<=0)
            return "";
        if(nRows==1)
            return s;
        int size=2*nRows-2;
        string res;
        for(int i=0;i<nRows;i++)  
        {  
            for(int j=i;j<s.length();j+=size)  
            {  
                res+=s[j];  
                if(i!=0 && i!=nRows-1 && j+size-2*i<s.length())  
                    res+=s[j+size-2*i];  
            }                  
        }  
        return res;
    }
};
