/*
Problem: Find Minimum in Rotated Sorted Array II  
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
        int begin=0,end=num.size()-1;
        while(begin<end)
        {
            int mid=(begin+end)/2;
            if(num[end]<num[mid]){
                begin=mid+1;
            }
            else if(num[mid]<num[end]){
                end=mid;
            }
            else{//num[mid]==num[end]
                if(num[begin]==num[mid]){//linear complexity
                    begin++;
                    end--;
                }
                else
                    end=mid;
            }
        }
        return num[end];
    }
};
