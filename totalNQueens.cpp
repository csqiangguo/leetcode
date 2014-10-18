/*
problem: N Queens
method: recursion
author: gq
*/
#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Solution {
public:
    int totalNQueens(int n) {
        if(n<=0)
            return 0;
        int count=0;
        vector<int> q(n,-1);
        place(0,n,q,count);
        return count;
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
    void place(int k,int n,vector<int> &q,int &count){
        if(k==n){
            count++;
        }
        else
        {
            for(int i=0;i<n;i++){
                if(can(k,i,q)){
                    q[k]=i;
                    place(k+1,n,q,count);
                }
            }
        }
    }
};
