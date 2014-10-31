/*
Problem: Insert Interval 
Method:   array bianli
Author: 'gq' 
*/
#include<iostream>
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
class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        vector<Interval> res;
        if(intervals.size()==0){
            res.push_back(newInterval);
            return res;
        }
        int i=0;
        while(i<intervals.size()){
            if(intervals[i].end<newInterval.start){
                res.push_back(intervals[i]);
                i++;
            }
            else
                break;
        }
        if(i==intervals.size()){
            res.push_back(newInterval);
            return res;
        }
        if(newInterval.end>=intervals[i].start){
            newInterval.start=min(newInterval.start,intervals[i].start);
            newInterval.end=max(newInterval.end,intervals[i].end);
            i++;
        }
        
        while(i<intervals.size()){
            if(intervals[i].start<=newInterval.end){
                newInterval.end=max(newInterval.end,intervals[i].end);
                i++;
            }
            else
                break;
        }
        res.push_back(newInterval);
        while(i<intervals.size()){
            res.push_back(intervals[i]);
            i++;
        }
        return res;
    }
};
