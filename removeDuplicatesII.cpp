/*
Problem: Remove Element
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
        int exist=1;
        for(int i=1;i<n;i++)
        {
            if(A[i]!=unique)
            {
                unique=A[i];
                exist=1;
                A[num]=A[i];
                num++;
            }
            else if(A[i]==unique&&exist<2)
            {
                exist++;
                A[num]=A[i];
                num++;
            }
            else
            {
                exist++;
            }
        }
        return num;
    }
};
