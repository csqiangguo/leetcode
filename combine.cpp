/*
problem: Combinations
method: recursion
author: gq
*/
#include<iostream>
#include<string>
#include<queue>
using namespace std;

class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int> >res;
        if(n<=0||k<=0||n<k)
            return res;
        if(k==1){
            for(int i=1;i<=n;i++)
                res.push_back(vector<int>(1,i));
            return res;
        }
        if(n==k)
        {
            vector<int> p;
            for(int i=1;i<=n;i++)
                p.push_back(i);
            res.push_back(p);
            return res;
        }
        vector<vector<int> >p1=combine(n-1,k);//no n
        for(int i=0;i<p1.size();i++)
            res.push_back(p1[i]);
        vector<vector<int> >p2=combine(n-1,k-1);
        for(int i=0;i<p2.size();i++){
            p2[i].push_back(n);
            res.push_back(p2[i]);
        }
        return res;
    }
};
