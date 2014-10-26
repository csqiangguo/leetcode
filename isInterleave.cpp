/*
Problem: Interleaving String
Method: DP 
Author: 'gq' 
*/
#include<iostream>
#include<cstdlib>
using namespace std;
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int len1 = s1.length(), len2 = s2.length(), len3 = s3.length();
        if(len3 != len1 + len2)return false;
        bool dp[len1 + 1][len2 + 1];
        res[0][0] = true;
        for(int i = 1; i <= len2; i++)dp[0][i] = res[0][i-1]&&s2.substr(0, i) == s3.substr(0, i);
        for(int i = 1; i <= len1; i++)res[i][0] = dp[i-1][0]&&s1.substr(0, i) == s3.substr(0, i);
        for(int i = 1; i <= len1; i++)
            for(int j = 1; j <= len2; j++){
                res[i][j] = (s3[i + j - 1] == s1[i - 1] && dp[i - 1][j]) ||
                            (s3[i + j - 1] == s2[j - 1] && dp[i][j - 1]);

            }

        return dp[len1][len2];
    }
};
