/*
Problem: Maximum Subarray
Method:  dynamic programming 
Author: 'gq' 
*/
#include<iostream>
#include<cstdlib>
#include<string> 
#include<algorithm>
using namespace std;
class Solution {
public:
    int maxSubArray(int A[], int n) {
    	if(n<=0)
    		return 0;
    	int max=A[0];
    	int pre=A[0];
    	for(int i=1;i<n;i++)
    	{
    		if(pre+A[i]>A[i])
    		{
    			pre=pre+A[i];
    		}
    		else
    			pre=A[i];
    		if(pre>max)
    			max=pre;
    	}
        return max;
    }
};
int main()
{
	int A[9]={-2,1,-3,4,-1,2,1,-5,4};
	Solution s;
	cout<<s.maxSubArray(A,9)<<endl;
	cin.get();
	return 0;
}
