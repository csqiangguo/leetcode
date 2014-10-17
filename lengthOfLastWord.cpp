/*
Problem: Longest Substring Without Repeating Characters
Method:  
Author: 'gq' 
*/
#include<iostream>
using namespace std;
class Solution {
public:
    int lengthOfLastWord(const char *s) {
        int final=0;
        int tmp=0;
        while(*s!='\0'){
            if(*s==' '){
                if(tmp!=0)
                    final=tmp;
                tmp=0;   
            }
            else{
                tmp++;
            }
            s++;
        }
        if(tmp!=0)
            final=tmp;
        return final;
    }
};
