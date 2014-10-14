/*
Problem: Triangle
Method: 
Author: 'gq' 
*/
#include<iostream>
using namespace std;
class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        if(triangle.empty())
            return 0;
        vector<vector<int>> res(triangle.size(),vector<int>());
        res[0]=triangle[0];
        for(int i=1;i<triangle.size();i++)
        {
            for(int j=0;j<triangle[i].size();j++)
            {
                if(j<triangle[i-1].size())
                {
                    res[i].push_back(res[i-1][j]+triangle[i][j]);
                }
                else
                {
                    res[i].push_back(INT_MAX);
                }
                if(0<=j-1)
                {
                    int sum=res[i-1][j-1]+triangle[i][j];
                    if(sum<res[i][j])
                        res[i][j]=sum;
                }
            }
        }
        return min(res[triangle.size()-1]);
    }
    int min(vector<int> res)
    {
        int MIN=INT_MAX;
        for(int i=0;i<res.size();i++)
        {
            if(res[i]<MIN)
                MIN=res[i];
        }
        return MIN;
    }
};
