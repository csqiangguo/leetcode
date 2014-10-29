/*
Problem: Anagrams
Method:  hash
Author: 'gq' 
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<string> 
using namespace std;
class Solution {
    public:
        vector<string> anagrams(vector<string> &strs) {
            vector<string> vec;
            map<string,vector<string>> mp;
            for(int i=0;i<strs.size();i++){                    //sort every string and store groups of strings that are anagrams in a map
                string tmp=strs[i];
                sort(tmp.begin(),tmp.end());
                mp[tmp].push_back(strs[i]);
            }
            for(auto keyValue:mp){                      // find all anagrams
                if(keyValue.second.size()>1)
                vec.insert(vec.end(),keyValue.second.begin(),keyValue.second.end());
            }
            return vec;
        }
    };
