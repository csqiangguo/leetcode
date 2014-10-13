/*
Problem: Subsets 
Method:  recursion
Author: 'gq' 
*/
#include<iostream>
using namespace std;
class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        vector<vector<int>> res;
        res.push_back(vector<int>());
        sort(S.begin(),S.end());
        for(int i=0;i<S.size();i++)
        {
            int size=res.size();
            for(int j=0;j<size;j++)
            {
                vector<int> temp=res[j];
                temp.push_back(S[i]);
                res.push_back(temp);
            }
        }
        return res;
    }
};

