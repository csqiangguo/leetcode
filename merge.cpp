/*
Problem: Merge Sorted Array 
Method: merge 
Author: 'gq' 
*/
#include<iostream>
using namespace std;
class Solution {
public:
    void merge(int A[], int m, int B[], int n){
         if(n<=0)
            return;
         int index=m+n-1,i=m-1,j=n-1;
         while(0<=i&&0<=j)
         {
            if(A[i]<B[j])
            {
               A[index]=B[j];
               j--;
               index--;
            }
            else
            {
                A[index]=A[i];
                i--;
                index--;
            }
         }
         if(0<=j)
         {
            for(;0<=j;--j)
               A[j]=B[j];
         }
    }        
};
int main()
{
	int A[5]={2};
	int B[1]={1};
	Solution s;
	s.merge(A,1,B,1);
	for(int i=0;i<5;i++)
	{
		cout<<A[i]<<endl;
	}
    cin.get();
    return 0;
}
