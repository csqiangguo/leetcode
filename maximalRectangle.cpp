/*
Problem: Maximum Product Subarray 
Method: dynamic program 
Author: 'gq' 
*/
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        if(matrix.size()==0||matrix[0].size()==0)
            return 0;
        int max=0;
        vector<int> height(matrix[0].size(),0);
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                height[j]=matrix[i][j]=='0'?0:height[j]+1;
            }
            if(max<largestRectangleArea(height))
                max=largestRectangleArea(height);
        }
        return max;
    }
    int largestRectangleArea(vector<int> &height) {

            int ret = 0;
            height.push_back(0);
            vector<int> index;

            for(int i = 0; i < height.size(); i++)
            {
                while(index.size() > 0 && height[index.back()] >= height[i])
                {
                    int h = height[index.back()];
                    index.pop_back();

                    int sidx = index.size() > 0 ? index.back() : -1;
                    if(h * (i-sidx-1) > ret)
                        ret = h * (i-sidx-1);
                }
                index.push_back(i);
            }

            return ret;
        }
};
