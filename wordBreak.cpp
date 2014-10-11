/*
Problem: Word Break 
Method:  DP 
Author: 'gq' 
*/
#include<iostream>
using namespace std;
class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        if(s.empty())
            return false;
        vector<bool> can(s.size()+1);
        can[0]=true;
        for(int i=1;i<=s.size();i++)
        {
            for(int j=0;j<i;j++)
            {
                string str=s.substr(j,i-j);
                if(can[j]&&dict.find(str)!=dict.end())
                {
                    can[i]=true;
                    break;
                }
            }
        }
        return can[s.size()];
    }
};
