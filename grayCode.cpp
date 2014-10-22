/*
Problem: Gray Code 
Method:   
Author: 'gq' 
*/
#include<iostream>
using namespace std;
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res;
        if(n<0)
            return res;
        if(n==0){
            res.push_back(0);
            return res;
        }
        int plus=2;
        res.push_back(0);
        res.push_back(1);
        for(int i=1;i<n;i++){
            int size=res.size();
            for(int j=size-1;0<=j;j--){
                res.push_back(res[j]+plus);
            }
            plus<<=1;
        }
        return res;
    }
};
