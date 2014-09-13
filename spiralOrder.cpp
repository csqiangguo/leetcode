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
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> res;
		if(matrix.size()==0)
			return res;
		int l1,l2,r1,r2;
		l1=0;r1=0;
		l2=matrix.size()-1;r2=matrix[0].size()-1;
		while(l1<=l2||r1<=r2)
		{
			for(int i=r1;i<=r2&&l1<=l2;i++)
			{
				res.push_back(matrix[l1][i]);
			}
			for(int i=l1+1;i<=l2&&r1<=r2;i++)
			{
				res.push_back(matrix[i][r2]);
			}
			for(int i=r2-1;r1<=i&&l1<l2;i--)
			{
				res.push_back(matrix[l2][i]);
			}
			for(int i=l2-1;l1+1<=i&&r1<r2;i--)
			{
				res.push_back(matrix[i][r1]);
			}
			l1++;r1++;
			l2--;r2--;
		}
		return res;
    }
};
int main()
{
	int a[1][3]={{1,2,3}};//,{4,5,6},{7,8,9}};
	vector<vector<int>> matrix;
	vector<int> t1(a[0],a[0]+3);
	matrix.push_back(t1);
//	vector<int> t2(a[1],a[1]+3);
//	matrix.push_back(t2);
//	vector<int> t3(a[2],a[2]+3);
//	matrix.push_back(t3);
	Solution s;
	vector<int> res;
	res=s.spiralOrder(matrix);
	for(int i=0;i<res.size();i++)
		cout<<res[i]<<' ';
	cout<<endl;
	cin.get();
	return 0;
}
