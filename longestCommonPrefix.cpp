/*
Problem: Longest Common Prefix
Method:  
Author: 'gq' 
*/
#include<iostream>
using namespace std;
class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        if(strs.empty())
            return "";
        if(strs.size()==1||strs[0].empty())
            return strs[0];
        string prefix=strs[0];
        while(!prefix.empty()){
            int i=1;
            for(;i<strs.size();i++){
                int j=0;
                for(;j<strs[i].size()&&j<prefix.size();j++){
                    if(strs[i][j]!=prefix[j])
                        break;
                }
                if(j!=prefix.size())
                    break;
            }
            if(i==strs.size())
                return prefix;
            prefix=prefix.substr(0,prefix.size()-1);
        }
        return prefix;
    }
};
