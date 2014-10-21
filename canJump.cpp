/*
problem: Jump Game
method: array
author: gq
*/
#include<iostream>
#include<string>
#include<queue>
using namespace std;
class Solution {
public:
    bool canJump(int A[], int n) {
        int last=n-1;
        for(int j=n-2;0<=j;j--){
            if(A[j]+j>=last)
                last=j;
        }
        return last==0;
    }
};
class Solution2 {
public:
    bool canJump(int A[], int n) {
        if(n<=1)
            return true;
        for(int i=0;i<n-1;i++){
            if(A[i]==0)
                return false;
            int j=i;
            while(j<n){
                if(j+A[j]>=n-1)
                    return true;
                else{
                    if(A[j+A[j]]==0)
                        break; 
                    else
                        j=j+A[j];
                }
            }
            
        }
        return false;
    }
};
