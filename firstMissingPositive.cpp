/*
Problem: First Missing Positive
Method:  array
Author: 'gq' 
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<string> 
using namespace std;
class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        if(n<=0)
            return 1;
        int i=0;
        while(i<n){
            if(A[i]==i+1)
            {
                i++;
            }
            else{
                if(A[i]>0&&A[i]<n&&A[A[i]-1]!=A[i]){
                    int tmp=A[A[i]-1];
                    A[A[i]-1]=A[i];
                    A[i]=tmp;
                }
                else{
                    i++;
                }
            }
        }
        for(int i=0;i<n;i++){
            if(A[i]!=i+1)
                return i+1;
        }
        return n+1;
    }
};

