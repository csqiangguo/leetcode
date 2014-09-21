/*
Problem: Longest Substring Without Repeating Characters
Method: window/dynamic program 
Author: 'gq' 
*/
#include<iostream>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()==0)
            return 0;
        int max=1;
        map<char,int> charMap;
        charMap[s[0]]=0;
        int lastIndex=-1;
        for(int i=1;i<s.size();i++)
        {
            if(charMap.find(s[i])!=charMap.end()&&lastIndex<charMap[s[i]])
            {
                lastIndex=charMap[s[i]];
            }
            charMap[s[i]]=i;
            if(max<i-lastIndex)
                max=i-lastIndex;
        }
        return max;
    }
};
