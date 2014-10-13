/*
Problem: Subsets II
Method:  recursion
Author: 'gq' 
*/
#include<iostream>
using namespace std;
class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        vector<vector<int>> res;
        res.push_back(vector<int>());
        if(S.empty())
            return res;
        sort(S.begin(),S.end());
        res.push_back(vector<int>(1,S[0]));
        int pre=1;
        for(int i=1;i<S.size();i++)
        {
            int add=0;
            if(S[i]!=S[i-1])
            {
                int size=res.size();
                for(int j=0;j<size;j++)
                {
                    res.push_back(res[j]);
                    res[res.size()-1].push_back(S[i]);
                    add++;
                }
                pre=add;
            }
            else
            {
                int size=res.size();
                for(int j=0;j<pre;j++)
                {
                    res.push_back(res[size-j-1]);
                    res[res.size()-1].push_back(S[i]);
                    add++;
                }
                pre=add;
            }
            
        }
        return res;
    }
};
