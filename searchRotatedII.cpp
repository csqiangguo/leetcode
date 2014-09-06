/*
Problem: Search in Rotated Sorted Array II 
Method: 二分法
Author: 'gq' 
与 Search in Rotated Sorted Array 的区别： 数组为11131和13111时， A[mid]==A[low]==A[high]无法判断哪边有序 ，可能左边有序，也可能右边有序 
*/
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    bool search(int A[], int n, int target) {
    	if(n<=0)
    		return false;
    	int low=0,high=n-1;
    	while(low<=high)
    	{
    		int mid=(low+high)/2;
    		if(A[mid]==target)
    			return true;
    		if(A[low]<A[mid])
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
    		else if(A[mid]<A[high])
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
    		else if(A[mid]==A[high]&&A[mid]==A[low])//无法判断有序时，线性 复杂度 
    		{
    			low++;
				high--;	
    		}
    		else if(A[mid]==A[high]&&A[mid]<A[low])
    		{
    			high=mid-1;
    		}
    		else
    		{
    			low=mid+1;
    		}
    	}
    	return false;   
    }
};
int main()
{
	int A[7]={3,1,2,2,2,3,3};//11131和13111 A[mid]==A[low]==A[high]无法判断哪边有序 
	Solution s;
	cout<<s.search(A,7,1)<<endl;
	cout<<s.search(A,5,-1)<<endl;
	cin.get();
	return 0;
} 
