/*
Problem: Set Matrix Zeroes  
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
    void setZeroes(vector<vector<int> > &matrix) {
        if(matrix.size()==0)
	   		return ;
	   	bool l0=false,r0=false;
		for(int i=0;i<matrix.size();i++)
		{
			for(int j=0;j<matrix[0].size();j++)
			{
				if(matrix[i][j]==0)
				{
					if(i==0)
						r0=true;
					if(j==0)
						l0=true;
					matrix[i][0]=0;
					matrix[0][j]=0;
				}
				
			}
		} 
		for(int i=1;i<matrix[0].size();i++)
		{
			if(matrix[0][i]==0)
			{
				for(int j=0;j<matrix.size();j++)
					matrix[j][i]=0;
			}
		}
		for(int i=1;i<matrix.size();i++)
		{
			if(matrix[i][0]==0)
			{
				for(int j=0;j<matrix[0].size();j++)
					matrix[i][j]=0;
			}
		}
		if(r0)
		{
			for(int i=1;i<matrix[0].size();i++)
				matrix[0][i]=0;
		}
		if(l0)
		{	
			for(int j=1;j<matrix.size();j++)
				matrix[j][0]=0;
		}
    }
};
int main()
{
	int a[3][3]={{1,2,0},{4,5,6},{7,8,9}};
	vector<vector<int>> matrix;
	vector<int> t1(a[0],a[0]+3);
	matrix.push_back(t1);
	vector<int> t2(a[1],a[1]+3);
	matrix.push_back(t2);
	vector<int> t3(a[2],a[2]+3);
	matrix.push_back(t3);
	Solution s;
	s.setZeroes(matrix);
	for(int i=0;i<matrix.size();i++)
	{
		for(int j=0;j<matrix[0].size();j++)
			cout<<matrix[i][j]<<' ';
		cout<<endl;
	}
	cin.get();
	return 0;
}
