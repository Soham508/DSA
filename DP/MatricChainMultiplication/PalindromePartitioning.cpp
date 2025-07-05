#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<bool>> pal;
    int minCut(string s) {
        vector<vector<int>> dp(s.length() + 1, vector<int>(s.length() + 1, -1));
        pal.resize(s.length() + 1,
                                 vector<bool>(s.length() + 1, false));
        for (int i = 0; i < s.length(); i++) {
            pal[i][i] = true;
        }
        int n = s.length();
        for (int i = n - 1; i >= 0; i--) {
            for (int j = n-1; j > i; j--) {
                if ((s[i] == s[j] && pal[i + 1][j - 1]) ||
                    (s[i] == s[j] && i + 1 == j)) {
                    pal[i][j] = true;
                }
            }
        }

        return solve(s, 0, s.length() - 1, dp);
    }


    int solve(string& s, int i, int j, vector<vector<int>>& dp) {
        if (i >= j) {
            return 0;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        if (pal[i][j] == true) {
            return 0;
        }

        int minCost = s.length()+1;

        for (int k = i; k < j; k++) {
            int cost = s.length()+1;
            if(pal[i][k]){
                cost = 1 + solve(s,k+1,j,dp);
            }
            minCost = min(minCost, cost);
        }

        return dp[i][j] = minCost;
    }
};