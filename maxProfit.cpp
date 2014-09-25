/*
Problem: Best Time to Buy and Sell Stock
Method: window/dynamic program 
Author: 'gq' 
*/
#include<iostream>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int> &prices) {
         if(prices.size()==0)
            return 0;
         int maxPro=0;
         int min=prices[0];
         for(int i=1;i<prices.size();i++)
         {
            if(prices[i]<min)
               min=prices[i];
            int curProfit=prices[i]-min;
            if(maxPro<curProfit)
               maxPro=curProfit;
         }
         return maxPro;
    }
};
