/*
Problem: Search in Rotated Sorted Array II 
Method: ���ַ�
Author: 'gq' 
�� Search in Rotated Sorted Array ������ ����Ϊ11131��13111ʱ�� A[mid]==A[low]==A[high]�޷��ж��ı����� �������������Ҳ�����ұ����� 
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
    		else if(A[mid]==A[high]&&A[mid]==A[low])//�޷��ж�����ʱ������ ���Ӷ� 
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
	int A[7]={3,1,2,2,2,3,3};//11131��13111 A[mid]==A[low]==A[high]�޷��ж��ı����� 
	Solution s;
	cout<<s.search(A,7,1)<<endl;
	cout<<s.search(A,5,-1)<<endl;
	cin.get();
	return 0;
} 
