/*
Problem: Permutations 
Method:  
Author: 'gq' 
*/
#include<iostream>
using namespace std;
class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        vector<vector<int>> res;
        if(num.empty())
            return res;
        sort(num.begin(),num.end());
        res.push_back(num);
        vector<int> p=*(--res.end());
        while(nextPermutation(p))
        {
            res.push_back(p);
        }
        return res;
    }
    bool nextPermutation(vector<int> &num){
		int i=num.size()-1;
		for(;0<i;i--)
		{
			if(num[i-1]<num[i])
				break;
		}
		i=i-1;
		if(i<0)
		{
			return false;
		}
		int j=i+1;
		for(;j<num.size();j++)
		{
			if(num[j]<=num[i])
			{
				break;
			}
		}
		j=j-1;
		swap(*(num.begin()+i),*(num.begin()+j));
		reverse(num.begin()+i+1,num.end());
		return true;
	}
};
