/*
Problem: Combination Sum II 
Method:  recursion	
Author: 'gq' 
*/
#include<iostream>
#include<string> 
#include<vector>
using namespace std;
class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        vector<vector<int>> res;
        if(num.empty())
            return res;
        sort(num.begin(),num.end());
        vector<int> tmp;
        helper(num,0,target,tmp,res);
        return res;
    }
    void helper(vector<int> &num,int start,int target,vector<int> tmp,vector<vector<int>> &res){
        if(target==0){
            res.push_back(tmp);
            return ;
        }
        if(target<0||num.size()<=start)
            return ;
        
        for(int i=start;i<num.size();i++){
            if(i>start && num[i]==num[i-1]) 
                continue; 
            tmp.push_back(num[i]);
            helper(num,i+1,target-num[i],tmp,res);
            tmp.pop_back();
        }
    }
};
