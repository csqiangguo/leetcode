/*
Problem: Search a 2D Matrix
Method: binary search
Author: 'gq' 
*/
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	bool binarySearch(vector<int> &vec,int target,int &pos)
	{
		if(vec.size()==0)
			return false;
		int low=0,high=vec.size()-1;
		while(low<=high)
		{
			int mid=(low+high)/2;
			if(vec[mid]==target)
			{
				pos=mid;
				return true;
			}
			if(vec[mid]<target)
				low=mid+1;
			else
				high=mid-1;
		}
		pos=low;
		return false;
	} 
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
    	if(matrix.size()==0)
    		return false;
    	if(matrix[0].size()==0)
    		return false;
    	vector<int> temp;
    	for(int i=0;i<matrix.size();i++)
    	{
    		temp.push_back(matrix[i][0]);
    	}
    	bool exist=0;
    	int row;
		exist=binarySearch(temp,target,row);
    	if(exist==true)
    		return true;
    	if(row==0)
    		return false;
    	int col;
    	exist=binarySearch(matrix[row-1],target,col);
    	return exist;      
    }
};
int main()
{
	vector<vector<int>> matrix;
	int array[3][4]={{1,3,5,7},{10,11,16,20},{23,30,34,50}};
	matrix.push_back(vector<int>(array[0],array[0]+3));
	matrix.push_back(vector<int>(array[1],array[1]+3));
	matrix.push_back(vector<int>(array[2],array[2]+3));
	Solution s;
	if(s.searchMatrix(matrix,93))
		cout<<"yes"<<endl;
	else
		cout<<"no"<<endl;
	cin.get();
	return 0;
}
