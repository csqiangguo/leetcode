/*
Problem: Count and Say 
Method: 
Author: 'gq' 
*/
#include<iostream>
using namespace std;
class Solution {
public:
    string countAndSay(int n) {
        if(n<=0)
            return "";
        int i=1;
        string str="1";
        while(i<n)
        {
            string newStr="";
            int j=0;
            
            while(j<str.size())
            {
                char ch=str[j];
                int num=0;
                while(str[j]==ch){
                    num++;
                    j++;
                }
                newStr+='0'+num;
                newStr+=ch;
            }
            str=newStr;
            i++;
        }
        return str;
    }
};
