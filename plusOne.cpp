/*
Problem: Plus One  
Method:  carry 
Author: 'gq' 
*/
#include<iostream>
#include<cstdlib>
#include<vector> 
#include<algorithm>
class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        vector<int> res;
        if(digits.empty())
            return res;
        int carry=1;
        for(int i=digits.size()-1;0<=i;i--)
        {
            int sum=digits[i]+carry;
            int remainder=sum%10;
            carry=sum/10;
            res.push_back(remainder);
        }
        if(carry==1)
            res.push_back(carry);
        reverse(res.begin(),res.end());
        return res;
    }
};
