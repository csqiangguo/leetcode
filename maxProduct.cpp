/*
Problem: Maximum Product Subarray 
Method: dynamic program 
Author: 'gq' 
*/
#include<iostream>
using namespace std;
class Solution {
public:
    int maxProduct(int A[], int n) {
        if(n<=0)
            return 0;
        int maxherepre = A[0];
        int minherepre = A[0];
        int maxsofar = A[0];
        int maxhere, minhere;

        for (int i = 1; i < n; i++) {
            maxhere = max(max(maxherepre * A[i], minherepre * A[i]), A[i]);
            minhere = min(min(maxherepre * A[i], minherepre * A[i]), A[i]);
            maxsofar = max(maxhere, maxsofar);
            maxherepre = maxhere;
            minherepre = minhere;
        }
        return maxsofar;
    }
    int max(int i,int j){
        return i<j?j:i;
    }
    int min(int i,int j){
        return i<j?i:j;
    }
};

