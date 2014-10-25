/*
Problem: Surrounded Regions
Method:	flood fill alg+BFS
Author: 'gq' 
*/
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Solution {
public:
    void solve(vector<vector<char> > &board) {
        if(board.empty()||board.size()<=2||board[0].size()<=2)
            return ;
        for(int i=0;i<board[0].size();i++){
            flood_fill(board,0,i);
            flood_fill(board,board.size()-1,i);
        }
        for(int j=1;j<board.size()-1;j++){
            flood_fill(board,j,0);
            flood_fill(board,j,board[0].size()-1);
        }
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]=='O')
                    board[i][j]='X';
                else if(board[i][j]=='#')
                    board[i][j]='O';
            }
        }
    }
    void flood_fill(vector<vector<char> > &board,int i,int j){
        if(board[i][j]!='O')
            return ;
        board[i][j]='#';
        if(i>0&&board[i-1][j]=='O')
            flood_fill(board,i-1,j);
        if(j>0&&board[i][j-1]=='O')
            flood_fill(board,i,j-1);
        if(i<board.size()-1&&board[i+1][j]=='O')
            flood_fill(board,i+1,j);
        if(j<board[0].size()-1&&board[i][j+1]=='O')
            flood_fill(board,i,j+1);
    }
};
class Solution1 {
public:
    void solve(vector<vector<char> > &board) {
        if(board.empty()||board.size()<=2||board[0].size()<=2)
            return ;
        for(int i=0;i<board[0].size();i++){
            flood_fill(board,0,i);
            flood_fill(board,board.size()-1,i);
        }
        for(int j=1;j<board.size()-1;j++){
            flood_fill(board,j,0);
            flood_fill(board,j,board[0].size()-1);
        }
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]=='O')
                    board[i][j]='X';
                else if(board[i][j]=='#')
                    board[i][j]='O';
            }
        }
    }
    void flood_fill(vector<vector<char> > &board,int i,int j){
        if(board[i][j]!='O')
            return ;
        board[i][j]='#';
        queue<int> q;
        int code=i*board[0].size()+j;
        q.push(code);
        while(!q.empty()){
            code=q.front();
            q.pop();
            i=code/board[0].size();
            j=code%board[0].size();
            if(i>0&&board[i-1][j]=='O'){
                q.push((i-1)*board[0].size()+j);
                board[i-1][j]='#';
            }
            if(j>0&&board[i][j-1]=='O'){
                q.push((i)*board[0].size()+j-1);
                board[i][j-1]='#';
            }
            if(i<board.size()-1&&board[i+1][j]=='O'){
                q.push((i+1)*board[0].size()+j);
                board[i+1][j]='#';
            }
            if(j<board[0].size()-1&&board[i][j+1]=='O'){
                q.push((i)*board[0].size()+j+1);
                board[i][j+1]='#';
            }
        }
    }
};
int main()
{
	vector<vector<char> > board(4,vector<char>(4,'X'));
	board[1][1]='O';
	board[1][2]='O';
	board[2][2]='O';
	board[3][1]='O';
	Solution1 s;
	s.solve(board);
	for(int i=0;i<board.size();i++){
		for(int j=0;j<board[0].size();j++)
			cout<<board[i][j]<<' ';
		cout<<endl;
	}
	return 0;
}

