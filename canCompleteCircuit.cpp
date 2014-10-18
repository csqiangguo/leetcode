/*
Problem: Gas Station
Method: 
Author: 'gq' 
*/
#include<iostream>
#include<string> 
using namespace std;
class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int lack=0;
        int remain=0;
        int start=0;
        for(int i=0;i<gas.size();i++){
            remain+=gas[i]-cost[i];
            if(remain<0){
                lack+=remain;
                start=i+1;
                remain=0;
            }
        }
        if(0<=lack+remain)
            return start;
        else
            return -1;
    }
};
