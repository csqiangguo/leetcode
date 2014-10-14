/*
Problem: Unique Paths
Method:  
Author: 'gq' 
*/
#include<iostream>
using namespace std;
class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m<1||n<1)
            return 0;
        vector<int> path(n,1);
        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                path[j]+=path[j-1];
            }
        }
        return path[n-1];
    }
};
