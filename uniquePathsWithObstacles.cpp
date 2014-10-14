/*
Problem: Unique Paths II 
Method:  
Author: 'gq' 
*/
#include<iostream>
using namespace std;
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        if(obstacleGrid.size()<1||obstacleGrid[0].size()<1)
            return 0;
        vector<int> path(obstacleGrid[0].size());
        for(int j=0;j<obstacleGrid[0].size();j++)
        {
            if(obstacleGrid[0][j]!=1)
                path[j]=1;
            else
                break;
        }
        for(int i=1;i<obstacleGrid.size();i++)
        {
            for(int j=0;j<obstacleGrid[0].size();j++)
            {
                if(obstacleGrid[i][j]==1)
                    path[j]=0;
                else
                {
                    if(j!=0)
                        path[j]+=path[j-1]; 
                }
            }
        }
        return path[obstacleGrid[0].size()-1];
    }
};
