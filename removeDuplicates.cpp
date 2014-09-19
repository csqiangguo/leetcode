/*
Problem: Remove Duplicates from Sorted Array
Method:  double indexs 
Author: 'gq' 
*/
#include<iostream>
using namespace std;
class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if(0==n)
            return 0;
        int num=1;
        int unique=A[0];
        for(int i=1;i<n;i++)
        {
            if(A[i]!=unique)
            {
                unique=A[i];
                A[num]=A[i];
                num++;
            }
        }
        return num;
    }
};
