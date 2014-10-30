/*
Problem: Trapping Rain Water
Method:  two pointers
Author: 'gq' 
*/
#include<iostream>
#include<string> 
using namespace std;
class Solution {
public:
    int trap(int A[], int n) {
        if(n<=0)
            return 0;
        int res=0;
        vector<int> container(n,0);
        int max=0;
        for(int i=0;i<n;i++){
            container[i]=max;
            max=max<A[i]?A[i]:max;
        }
        max=0;
        for(int i=n-1;i>=0;i--){
            container[i]=max<container[i]?max:container[i];
            max=max<A[i]?A[i]:max;
            res+=container[i]-A[i]>0?container[i]-A[i]:0;
        }
        return res;
    }
};
