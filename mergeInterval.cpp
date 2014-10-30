/*
Problem: Merge Intervals
Method: array sort
Author: 'gq' 
*/
#include<iostream>
#include<cstdlib>
#include<vector> 
using namespace std;
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
bool cmp(Interval a, Interval b){
    return a.start<b.start;
}
class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        if(intervals.size()<2)
            return intervals;
        sort(intervals.begin(),intervals.end(),cmp);
        vector<Interval> res;
        res.push_back(intervals[0]);
        for(int i=1;i<intervals.size();i++){
            if(intervals[i].start<=res[res.size()-1].end){
                if(intervals[i].end>res[res.size()-1].end)
                    res[res.size()-1].end=intervals[i].end;
            }
            else{
                res.push_back(intervals[i]);
            }
        }
        return res;
    }
};
