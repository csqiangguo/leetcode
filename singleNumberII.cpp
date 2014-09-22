/*
Problem: Single NumberII
Method: window/dynamic program 
Author: 'gq' 
*/
#include<iostream>
using namespace std;
class Solution 
{
public:
	//
    int singleNumber(int A[], int n) 
	{
        if(n<1||n==2||n==3)
			return 0;
		if(n==1)
			return A[0];
		int bit=0;
		int result=0;
		for(int i=31;i>=0;i--)//计算数组中所有数第i位1的个数的和
		{
			bit=0;
			for(int j=0;j<n;j++)
			{
				bit+=(A[j]>>i)&1;
			}
			bit=bit%3;
			result=result*2+bit;
		}
		return result;
    }
};
