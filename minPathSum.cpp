/*
Problem: Minimum Path Sum
Method:  
Author: 'gq' 
*/
#include<iostream>
using namespace std;
class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        if(grid.size()==0)
            return 0;
        vector<int> path=grid[0];
        for(int i=1;i<grid[0].size();i++)
        {
            path[i]=grid[0][i]+path[i-1];
        }
        for(int i=1;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            
            {
                if(j==0)
                    path[j]+=grid[i][j];
                else
                {
                    if(path[j-1]+grid[i][j]<path[j]+grid[i][j])
                        path[j]=path[j-1]+grid[i][j];
                    else
                        path[j]=path[j]+grid[i][j];
                }
            }
        }
        return path[grid[0].size()-1];
    }
};
