/*
Problem: Palindrome Partitioning II
Method: 
Author: 'gq' 
*/
#include<iostream>
using namespace std;
class Solution {
public:
    int minCut(string s) {
        vector<vector<int>> mark(s.length(),vector<int>());
        vector<vector<bool>> dict=getDict(s);
        for(int stop=s.length();stop>=0;stop--){
            if(stop<s.size()&&mark[stop].empty())continue;
            for(int start=stop-1;start>=0;start--)
                if(dict[start][stop-1])
                    mark[start].push_back(stop);
        }
        string res;
        collect(mark,0,s,"",res);
        return res.size()-s.size();
    }
    void collect(vector<vector<int>>& mark, int ind, const string& s, 
            string path, string& result){
			for(int i=0;i<mark[ind].size();i++){
				int stop=mark[ind][i];
				string sub=s.substr(ind,stop-ind);
				string newpath=path+(ind==0?sub:" "+sub);
				if(stop==s.length()){
				    if(newpath.size()<result.size()) 
					    result=newpath;
				}
				else 
					collect(mark,stop,s,newpath,result);
			}
    }
    vector<vector<bool>> getDict(string s){
        vector<vector<bool>> dict;
        for(int i=0;i<s.size();i++){
            dict.push_back(vector<bool>(s.size(),false));
        }
        for(int i=s.length()-1;0<=i;i--){
            for(int j=i;j<s.length();j++){
                if(s[i]==s[j]&&((j-i<2)||dict[i+1][j-1])){
                    dict[i][j]=true;
                }
            }
        }
        return dict;
    }
};
