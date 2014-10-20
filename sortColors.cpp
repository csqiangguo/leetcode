/*
Problem: Sort Colors 
Method:  DP 
Author: 'gq' 
*/
#include<iostream>
using namespace std;
class Solution {
public:
    void sortColors(int A[], int n) {
        if(n<=1)
            return ;
        int red=-1,white=-1,blue=-1;
        int i=0;
        while(i<n){
            if(A[i]==0){
                A[++blue]=2;
                A[++white]=1;
                A[++red]=0;
            }
            else if(A[i]==1){
                A[++blue]=2;
                A[++white]=1;
            }
            else if(A[i]==2){
                A[++blue]=2;
            }
            i++;
        }
    }
};
