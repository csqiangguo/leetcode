/*
problem: Jump Game II
method: DP
author: gq
*/
#include<iostream>
#include<string>
#include<queue>
using namespace std;

/*
 * We use "lastReach" to keep track of the maximum distance that has been reached
 * by using the minimum steps "step", whereas "reach" is the maximum distance
 * that can be reached by using "step+1" steps. Thus,
 * reach = max(reach,i+A[i]) where 0 <= i <= last.
 */
class Solution {
public:
    int jump(int A[], int n) {
        int step = 0;
        int lastReach = 0;
        int reach = 0;
        for (int i = 0; i < n; ++i) {
            if (i > lastReach) {
                lastReach = reach;
                ++step;
            }
            reach = max(reach, i+A[i]);
        }

        return step;
    }
};
