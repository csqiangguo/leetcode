/*
Problem: Max Points on a Line
Method: (points[k].y-points[i].y)*(points[j].x-points[i].x)==(points[j].y-points[i].y)*(points[k].x-points[i].x) 
Author: 'gq' 
*/
#include<iostream>
#include<cstdlib>
#include<vector> 
using namespace std;

struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};

class Solution {
public:
    int maxPoints(vector<Point> &points) {
        if(points.size()==0)
            return 0;
        if(allsamepoints(points))
            return points.size();
        int max=0;
        for(int i=0;i<points.size();i++)
        {
            for(int j=i+1;j<points.size();j++)
            {
                if((points[i].x==points[j].x)&&(points[i].y==points[j].y))
                    continue;
                int cur=2;
                for(int k=0;k<points.size();k++)
                {
                    if(k!=i&&k!=j&&((points[k].y-points[i].y)*(points[j].x-points[i].x)==(points[j].y-points[i].y)*(points[k].x-points[i].x)))
                    cur++;
                }
                if(cur>max)
                    max=cur;
            }
        }
        return max;
    }
    bool allsamepoints(vector<Point> points)
    {
        for(int i=1;i<points.size();i++)
        {
            if((points[0].x!=points[i].x)||(points[0].y!=points[i].y))
                return false;
        }
        return true;
    }
};
