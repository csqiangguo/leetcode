/*
Problem: Permutation Sequence 
Method:  math
Author: 'gq' 
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<string> 
using namespace std;
class Solution {
public:
    string getPermutation(int n, int k) {
        if(n<=0)
            return "";
        int f=1;
        int i,j;
        vector<int> num(n,0);
        for(i=1;i<=n;i++){
            f*=i;
            num[i-1]=i;
        }
        if(k>f)
            return "";
        k--;
        string res;
        for(i=0;i<n;i++){
            f=f/(n-i);
            int index=k/f;
            res.push_back(num[index]+'0');
            for(j=index;j<n-i-1;j++)
                num[j]=num[j+1];
            k=k%f;
        }
        return res;
    }
};
