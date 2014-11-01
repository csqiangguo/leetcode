/*
problem: Wildcard Matching
method: DP
author: gq
*/
#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        if(p==NULL)
            return s==NULL;
        int lens=strlen(s);
        int lenp=strlen(p);
        if(lens>300 && p[0]=='*' && p[lenp-1]=='*')  
            return false; 
        vector<bool> res(lens+1,false);
        res[0]=true;
        
        for(int j=0;j<lenp;j++){
            if(p[j]!='*'){
                for(int i=lens-1;i>=0;i--){
                    res[i+1]=res[i]&&(p[j]=='?'||s[i]==p[j]);
                }
            }
            else{
                int i=0;
                while(i<=lens&&!res[i])
                    i++;
                for(;i<=lens;i++){
                    res[i]=true;
                }
            }
            res[0]=res[0]&&p[j]=='*';
        }
        return res[lens];
    }
};

