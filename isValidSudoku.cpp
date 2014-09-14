/*
Problem: Valid Sudoku   
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
    bool isValidSudoku(vector<vector<char> > &board) {
    	if(board.size()==0)
    		return false;
    	for(int i=0;i<board.size();i++)
    	{
    		vector<int> stateRow(9,0);
    		vector<int> stateCol(9,0);
    		for(int j=0;j<board.size();j++)
    		{
    			if(board[i][j]!='.')
    			{
    				int index=board[i][j]-'0';
    				if(stateRow[index-1]==0)
    					stateRow[index-1]=1;
    				else
    					return false;
    			}
    			if(board[j][i]!='.')
    			{
    				int index=board[j][i]-'0';
    				if(stateCol[index-1]==0)
    					stateCol[index-1]=1;
    				else
    					return false;
    			}
    		}
    	}
    	for(int i=0;i<board.size();i+=3)
    	{
    		for(int j=0;j<board[0].size();j+=3)
    			if(!isValid(board,i,j))
    				return false;
    	}
        return true;
    }
    bool isValid(vector<vector<char> > &board,int i,int j) {
    	vector<int> state(9,0);
    	for(int m=i;m<i+3;m++)
    	{
    		for(int n=j;n<j+3;n++)
    		{
    			if(board[m][n]!='.')
    			{
    				int index=board[m][n]-'0';
    				if(state[index-1]==0)
    					state[index-1]=1;
    				else
    					return false;
    			}
    		}
    	}
    	return true;
    }
};
int main()
{
	char a[3][3]={{'1','2','3'},{'4','.','6'},{'4','8','9'}};//{{1,2,3},{4,5,6},{7,8,9}};
	vector<vector<char>> matrix;
	vector<char> t1(a[0],a[0]+3);
	matrix.push_back(t1);
	vector<char> t2(a[1],a[1]+3);
	matrix.push_back(t2);
	vector<char> t3(a[2],a[2]+3);
	matrix.push_back(t3);
	Solution s;
	if(s.isValidSudoku(matrix))
		cout<<"yes"<<endl;
	else
		cout<<"no"<<endl;
	cin.get();
	return 0;
}
