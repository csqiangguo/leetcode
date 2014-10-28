/*
Problem: Word Ladder 
Method:  
Author: 'gq' 
*/
#include<iostream>
#include<queue>
#include<unorder_set>
using namespace std;
class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        if(start.empty()||end.empty())
            return 0;
        unordered_set<string> visited;
        queue<string> q;
        int level=1;
        int levelNum=1;
        q.push(start);
        visited.insert(start);
        while(!q.empty()){
            string cur=q.front();
            q.pop();
            
            levelNum--;
            for(int i=0;i<cur.length();i++){
                string chilStr=cur;
                for( char c='a';c<='z';c++){
                    chilStr[i]=c;
                    if(chilStr==end)
                        return level+1;
                    if(dict.count(chilStr)>0&&visited.count(chilStr)==0)
                    {
                        q.push(chilStr);
                        visited.insert(chilStr);
                        
                    }
                }
            }
            if(levelNum==0){
                levelNum=q.size();
                level++;
            }
        }
         return 0;   
    }
};
