/*
Problem: Pascal's Triangle
Method:  
Author: 'gq' 
*/
#include<iostream>
using namespace std;
class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int>> res(numRows,vector<int>());
        if(numRows<=0)
            return res;
        res[0].push_back(1);
        for(int i=1;i<numRows;i++)
        {
            for(int j=0;j<=i;j++)
            {
                if(j<i)
                {
                    res[i].push_back(res[i-1][j]);
                }
                else
                {
                    res[i].push_back(0);
                }
                if(0<=j-1)
                {
                    res[i][j]+=res[i-1][j-1];
                }
            }
        }
        return res;
    }
};
