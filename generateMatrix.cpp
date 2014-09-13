/*
Problem: Spiral Matrix  
Method:  index 
Author: 'gq' 
*/
#include<iostream>
#include<cstdlib>
#include<vector> 
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int> > generateMatrix(int n){
        vector<vector<int>> res;
		if(n<=0)
			return res;
		for(int i=0;i<n;i++)
		{
			vector<int> temp(n,0);
			res.push_back(temp);
		}
		int l1,l2,r1,r2;
		l1=0;r1=0;
		l2=n-1;r2=n-1;
		int j=1;
		while(l1<=l2&&r1<=r2)
		{
			for(int i=r1;i<=r2;i++)
			{
				res[l1][i]=j;
				j++;
			}
			l1++;
			for(int i=l1;i<=l2;i++)
			{
				res[i][r2]=j;
				j++;
			}
			r2--;
			for(int i=r2;r1<=i&&l1<=l2;i--)//l1<=l2,两列不能重合 
			{
				res[l2][i]=j;
				j++;
			}
			l2--;
			for(int i=l2;l1<=i&&r1<=r2;i--)
			{
				res[i][r1]=j;
				j++;
			}
			r1++;
		}
		return res;
    }
};
int main()
{
	int n=2;
	Solution s;
	vector<vector<int>> res;
	res=s.generateMatrix(n);
	for(int i=0;i<res.size();i++)
		for(int j=0;j<res[0].size();j++)
			cout<<res[i][j]<<' ';
	cout<<endl;
	cin.get();
	return 0;
}
