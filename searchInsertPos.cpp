/*
Problem: Search Insert Position
Method: ¶þ·Ö·¨
Author: 'gq' 
*/
#include<iostream>
using namespace std;
class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        int low=0;
        int high=n-1;
        int mid;
        while(low<=high)
        {
            mid=(low+high)/2;
            if(A[mid]==target)
                return mid;
            if(A[mid]<target)
                low=mid+1;
            else
                high=mid-1;
        }
        return low;
    }
}; 
