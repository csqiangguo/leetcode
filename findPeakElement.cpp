/*
Problem: Find Peak Element  
Method:  binary search
Author: 'gq' 
*/
#include<iostream>
#include<vector>
#include<algorithm> 
using namespace std;
class Solution {
public:
    int findPeakElement(const vector<int> &num) {
        for(int i=1;i<num.size();i++){
            if(num[i]<num[i-1])
                return i-1;
        }
        return num.size()-1;
    }
};
class Solution {
public:
    int findPeakElement(const vector<int> &num) {
        int left=0,right=num.size()-1;
        while(left<=right){
            if(left==right)
                return left;
            int mid=(left+right)/2;
            if(num[mid]<num[mid+1])
                left=mid+1;
            else
                right=mid;
        }
    }
};

