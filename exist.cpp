/*
Problem: Word Search 
Method:  array+dfs
Author: 'gq' 
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<string> 
using namespace std;
class Solution {
public:
    bool exist(vector<vector<char> > &board, string word) {
        if(board.empty()||board[0].empty()||word.empty())
            return false;
        vector<vector<bool>> visited(board.size(),vector<bool>(board[0].size(),false));
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(DFS(board,word,0,i,j,visited))
                    return true;
            }
        }
        return false;
    }
    bool DFS(vector<vector<char>> &board,string word,int start,int i,int j,vector<vector<bool>> &visited){
        if(start==word.length())
            return true;
        if(i<0||j<0||i>=board.size()||j>=board[0].size()||visited[i][j]||board[i][j]!=word[start])
            return false;
        visited[i][j]=true;
        bool res=DFS(board,word,start+1,i-1,j,visited)||DFS(board,word,start+1,i,j-1,visited)||
                 DFS(board,word,start+1,i+1,j,visited)||DFS(board,word,start+1,i,j+1,visited);
        visited[i][j]=false;
        return res;
    }
};
