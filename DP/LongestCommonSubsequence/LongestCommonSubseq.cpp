#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;


// Top-Down (Memoization)

int lcsMemoHelper(const string& s1, const string& s2, int i, int j, vector<vector<int>>& dp) {
    if (i == 0 || j == 0)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];

    if (s1[i - 1] == s2[j - 1])
        return dp[i][j] = 1 + lcsMemoHelper(s1, s2, i - 1, j - 1, dp);
    else
        return dp[i][j] = max(lcsMemoHelper(s1, s2, i - 1, j, dp), lcsMemoHelper(s1, s2, i, j - 1, dp));
}

int lcsMemoization(const string& s1, const string& s2) {
    int n = s1.size(), m = s2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    return lcsMemoHelper(s1, s2, n, m, dp);
}

// Bottom-Up (Tabulation) LCS

int lcsBottomUp(const string& s1, const string& s2) {
    int n = s1.size(), m = s2.size();
    int dp[1001][1001] = {0}; 

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[n][m];
}

int main() {
    string text1 = "abcde";
    string text2 = "ace";

    cout << "Top-Down (Memoization) LCS length: " << lcsMemoization(text1, text2) << endl;
    cout << "Bottom-Up (Tabulation) LCS length: " << lcsBottomUp(text1, text2) << endl;

    return 0;
}
