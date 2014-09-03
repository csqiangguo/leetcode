/*
Problem: Sqrt(x)
Method: ¶þ·Ö·¨
Author: 'gq' 
*/
#include<iostream>
using namespace std;
class Solution {
public:
    int sqrt(int x) {
        if(x==0)
            return 0;
        int l=1;
        int r=x/2+1;
        while(l<=r)
        {
            int m=(l+r)/2;
            if(m<=x/m&&x/(m+1)<(m+1))
                return m;
            if(x/m<m)
                r=m-1;
            else
                l=m+1;
        }
        return 0;
    }
};

