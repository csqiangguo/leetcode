/*
Problem: Longest Consecutive Sequence   
Method:  
Author: 'gq' 
*/
#include<iostream>
#include<cstdlib> 
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        unordered_map<int, int> tail;
        for(vector<int>::iterator iter=num.begin();iter!=num.end();iter++){
            if(0<tail.count(*iter))
                continue;
            tail[*iter]=*iter; //cur begin
            if(0<tail.count(*iter-1)){
                tail[*iter]=tail[*iter-1];// cur begin
                tail[tail[*iter-1]]=*iter;
            }
            if(0<tail.count(*iter+1)){
                int last = tail[*iter+1]; // Find out the tail
                tail[last] = tail[*iter]; // Update tail's head
                tail[tail[*iter]] = last; 
            }
        }
        int longest=0;
        for (auto it = tail.begin(); it != tail.end(); it++)
            if (longest<it->second - it->first) 
                longest = it->second - it->first;
        return longest + 1;
    }
};
