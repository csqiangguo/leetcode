/*
Problem: Find Minimum in Rotated Sorted Array 
Method: binary search 
Author: 'gq' 
*/
#include<iostream>
using namespace std;
class Solution {
public:
    int findMin(vector<int> &num) {
        if(num.empty())
            return 0;
        int i=0,j=num.size()-1;
        while(i<j)
        {
            int mid=(i+j)/2;
            if(num[j]<num[mid]){
                i=mid+1;
            }
            else{
                j=mid;
            }
        }
        return num[j];
    }
};
