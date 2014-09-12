/*
Problem: Maximum Subarray
Method:  dynamic programming 
Author: 'gq' 
*/
#include<iostream>
#include<cstdlib>
#include<string> 
#include<algorithm>
using namespace std;
class Solution {
public:
    int numTrees(int n) {
        if(n==0||n==1)//0 null tree
        	return 1;
        int num=0;
        for(int i=1;i<=n;i++)
        {
        	num+=numTrees(i-1)*numTrees(n-i);
        }
        return num;
    }
};
int main()
{
	int n=4;
	Solution s;
	cout<<s.numTrees(n)<<endl;
	cin.get();
	return 0;
}

