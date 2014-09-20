/*
Problem: Median of Two Sorted Arrays
Method: 从两个顺序数组中找出第 k 大数 
Author: 'gq' 
*/
#include<iostream>
using namespace std;

class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        if(!haystack||!needle||strlen(needle)==0)
            return haystack;
        int len1=strlen(haystack);
        int len2=strlen(needle);
        for(int i=0;i<=len1-len2;i++)
        {
            int j=0;
            for(;j<len2;j++)
            {
                if(haystack[i+j]!=needle[j])
                    break;
            }
            if(j==len2)
                return haystack+i;
        }
        return NULL;
    }
};

class Solution1 {
public:
    char *strStr(char *haystack, char *needle) {
        if(!haystack||!needle||strlen(needle)==0)
            return haystack;
        int len1=strlen(haystack);
        int len2=strlen(needle);
        for(int i=0;i<=len1-len2;i++)
        {
            int j=len2-1;
            for(;0<=j&&needle[j]==haystack[i+j];--j);
            if(j<0)
                return haystack+i;
        }
        return NULL;
    }
};
