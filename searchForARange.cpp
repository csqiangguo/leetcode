/*
Problem: Search for a range
Method: binary search
Author: 'gq' 
*/
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	int findUpperBound(int A[],int n,int target)
	{
		if(n==0)
			return -1;
		int low=0;
		int high=n-1;
		bool exist=0;
		while(low<=high)
		{
			int mid=(low+high)/2;
			if(A[mid]==target)
				exist=1;
			if(A[mid]<=target)
			{
				low=mid+1;
			}
			else
			{
				high=mid-1;
			}
		}
		if(exist)
			return low-1;
		else
			return -1;
	}
	int findLowerBound(int A[],int n,int target)
	{
		if(n==0)
			return -1;
		int low=0;
		int high=n-1;
		bool exist=0;
		while(low<=high)
		{
			int mid=(low+high)/2;
			if(A[mid]==target)
				exist=1;
			if(A[mid]<target)
			{
				low=mid+1;
			}
			else
			{
				high=mid-1;
			}
		}
		if(exist)
			return high+1;
		else
			return -1;
	}
    vector<int> searchRange(int A[], int n, int target) {
    	vector<int> result;
    	result.push_back(findLowerBound(A,n,target));
    	result.push_back(findUpperBound(A,n,target));
    	return result;      
    }
}; 
int main()
{
	int A[6]={5, 7, 7, 8, 8, 10};
	int target=9;
	Solution s;
	vector<int> res;
	res=s.searchRange(A,6,target);
	cout<<res[0]<<' '<<res[1]<<endl;
	cin.get();
	return 0;
}
