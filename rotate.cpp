/*
Problem: Rotate Image  
Method:  rotate+reverse 
Author: 'gq' 
*/
#include<iostream>
#include<cstdlib>
#include<vector> 
#include<algorithm>
using namespace std;
class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
    	//副对角线转置矩阵 
    	for(int i=0;i<matrix.size();i++)
    	{
			for(int j=i+1;j<matrix[0].size();j++)
			{
				int temp=matrix[i][j];
				matrix[i][j]=matrix[j][i];
				matrix[j][i]=temp;
			} 
    	}
    	for(int i=0;i<matrix.size();i++)
    		reverse(matrix[i].begin(),matrix[i].end());
    }
};
int main()
{
	int a[3][3]={{1,2,3},{4,5,6},{7,8,9}};
	vector<vector<int>> matrix;
	vector<int> t1(a[0],a[0]+3);
	matrix.push_back(t1);
	vector<int> t2(a[1],a[1]+3);
	matrix.push_back(t2);
	vector<int> t3(a[2],a[2]+3);
	matrix.push_back(t3);
	Solution s;
	s.rotate(matrix);
	for(int i=0;i<matrix.size();i++)
	{
		for(int j=0;j<matrix[0].size();j++)
			cout<<matrix[i][j]<<' ';
		cout<<endl;
	}
	cin.get();
	return 0;
}
