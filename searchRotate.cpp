/*
Problem: Search in Rotated Sorted Array 
Method: ¶þ·Ö·¨
Author: 'gq' 
*/
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int search(int A[], int n, int target) {
    	if(n<=0)
    		return -1;
    	int low=0,high=n-1;
    	while(low<=high)
    	{
    		int mid=(low+high)/2;
    		if(A[mid]==target)
    			return mid;
    		if(A[low]<=A[mid])//= for [3,1]
    		{
    			if(A[low]<=target&&target<A[mid])
    			{
    				high=mid-1;
    			}
    			else
    			{
    				low=mid+1;
    			}
    		}
    		else
    		{
    			if(A[mid]<target&&target<=A[high])
    			{
    				low=mid+1;
    			}
    			else
    			{
    				high=mid-1;
    			}
    		}
    	}
    	return -1;   
    }
};
int main()
{
	int A[7]={3,1};
	Solution s;
	cout<<s.search(A,2,1)<<endl;
	cout<<s.search(A,2,-1)<<endl;
	cin.get();
	return 0;
} 
