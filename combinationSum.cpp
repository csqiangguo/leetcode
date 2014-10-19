/*
Problem: Combination Sum
Method:  recursioon
Author: 'gq' 
*/
#include<iostream>
#include<string> 
#include<vector>
using namespace std;
class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        vector<vector<int>> res;
        if(candidates.empty())
            return res;
        sort(candidates.begin(),candidates.end());
        vector<int> tmp;
        helper(candidates,0,target,tmp,res);
        return res;
    }
    void helper(vector<int> &candidates,int start,int target,vector<int> tmp,vector<vector<int>> &res){
        if(target<0)
            return ;
        if(target==0){
            res.push_back(tmp);
            return ;
        }
        for(int i=start;i<candidates.size();i++){
            if(0<i&&candidates[i-1]==candidates[i])continue;
            tmp.push_back(candidates[i]);
            helper(candidates,i,target-candidates[i],tmp,res);
            tmp.erase(--tmp.end());
        }
    }
};
