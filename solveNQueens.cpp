/*
Problem: N-Queens
Method: 
Author: 'gq' 
*/
#include<iostream>
#include<string> 
using namespace std;
class Solution {
public:
    vector<vector<string>> res;
    vector<vector<string> > solveNQueens(int n) {
        if(n<=0)
            return res;
        vector<int> q(n,-1);
        place(0,n,q);
        return res;
    }
    void print(int n,vector<int> &q){
        string str(n,'.');
        vector<string> tmp(n,str);
        for(int i=0;i<n;i++){
            tmp[i][q[i]]='Q';
        }
        res.push_back(tmp);
    }
    bool can(int row,int col,vector<int> &q){
        int j=0;
        while(j<row){
            if(q[j]==col||abs(row-j)==abs(col-q[j]))
                return false;
            j++;
        }
        return true;
    }
    void place(int k,int n,vector<int> &q){
        if(k==n){
            print(n,q);
        }
        else
        {
            for(int i=0;i<n;i++){
                if(can(k,i,q)){
                    q[k]=i;
                    place(k+1,n,q);
                }
            }
        }
    }
};
