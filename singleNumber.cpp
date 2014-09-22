/*
Problem: Single Number
Method: window/dynamic program 
Author: 'gq' 
*/
#include<iostream>
using namespace std;
class Solution {
public:
    int singleNumber(int A[], int n) {
        if(n<1||A==NULL)
            return -1;
        int result=A[0];
        for(int i=1;i<n;i++)
            result^=A[i];
        return result;
    }
};
