/*
Problem: Distinct Subsequences  
Method:  DP 
Author: 'gq' 
*/
#include<iostream>
#include<vector>
#include<string> 
using namespace std;
class Solution1{
public:
    int numDistinct(string S, string T) {
    if(T.length()==0)
    {
        return 1;
    }
    if(S.length()==0)
        return 0;
    vector<int>res(T.length()+1);
    res[0] = 1;
    for(int i=0;i<S.length();i++)
    {
        for(int j=T.length()-1;j>=0;j--)
        {
            res[j+1] = (S[i]==T[j]?res[j]:0)+res[j+1];
        }
    }
    return res[T.length()];
}
};
class Solution {
public:
    int numDistinct(string S, string T) {
        if(T.empty())
            return 1;
        if(S.size()<T.size())
            return 0;
        vector<vector<int> > res(S.size(),vector<int>());
        for(int i=0;i<S.size();i++){
            res[i]=vector<int>(T.size(),0);
        }
	for(int i=0;i<S.size();i++){
            if(S[i]==T[0]){
		if(i==0)
		   res[i][0]=1;
		else
		   res[i][0]=res[i-1][0]+1;
	    }
	    else{
		if(i==0)
		   res[i][0]=0;
		else
		   res[i][0]=res[i-1][0];
	    }
	}  	
        for(int i=0;i<S.size();i++){
            for(int j=1;j<=i&&j<T.size();j++){
                if(T[j]!=S[i]){
                    res[i][j]=res[i-1][j];
                }
                else{
                     res[i][j]=res[i-1][j-1]+res[i-1][j];
                    }
                }
            }
        return res[S.size()-1][T.size()-1];
    }
};
int main(){
	string s="rr";
	string t="r";
  	Solution S;
	cout<<S.numDistinct(s,t)<<endl;
	return 0;
}
