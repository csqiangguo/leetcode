/*
Problem: Palindrome Partitioning 
Method: 
Author: 'gq' 
*/
#include<iostream>
using namespace std;
class Solution {
public:
    vector<vector<string>> partition(string s){
        vector<string> res=partition1(s);
        vector<vector<string>> result;
        for(int i=0;i<res.size();i++){
            vector<string> vtmp;
            string tmp;
		    for(int j=0;j<res[i].size();j++){
			    if(res[i][j]!=' '){
			        tmp+=res[i][j];
			    }
			    else{
			        vtmp.push_back(tmp);
			        tmp="";
			    }
		    }
		    if(!tmp.empty())
		        vtmp.push_back(tmp);
		    result.push_back(vtmp);
	    }
	    return result;
    }
    vector<string> partition1(string s) {
        vector<vector<int>> mark(s.length(),vector<int>());
        vector<vector<bool>> dict=getDict(s);
        for(int stop=s.length();stop>=0;stop--){
            if(stop<s.size()&&mark[stop].empty())continue;
            for(int start=stop-1;start>=0;start--)
                if(dict[start][stop-1])
                    mark[start].push_back(stop);
        }
        vector<string> res;
        collect(mark,0,s,"",res);
        return res;
    }
    void collect(vector<vector<int>>& mark, int ind, const string& s, 
            string path, vector<string>& result){
			for(int i=0;i<mark[ind].size();i++){
				int stop=mark[ind][i];
				string sub=s.substr(ind,stop-ind);
				string newpath=path+(ind==0?sub:" "+sub);
				if(stop==s.length()) 
					result.push_back(newpath);
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
