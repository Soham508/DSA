#include <iostream>
#include <vector>
#include <string>
using namespace std;

int helper(const string& s1, const string& s2, int i, int j, int count, vector<vector<vector<int>>>& dp) {
    if (i == 0 || j == 0)
        return count;

    if (dp[i][j][count] != -1)
        return dp[i][j][count];

    int result = count;

    if (s1[i - 1] == s2[j - 1]) {
        result = helper(s1, s2, i - 1, j - 1, count + 1, dp);
    }

    // Either skip s1[i-1] or s2[j-1] — and reset count
    // For cases like - s1 = "abcdscsadas" s2 = "abcsvasabcd"
    result = max(result, max(
        helper(s1, s2, i - 1, j, 0, dp),
        helper(s1, s2, i, j - 1, 0, dp)
    ));

    return dp[i][j][count] = result;
}

int longestCommonSubstring(string s1, string s2) {
    int n = s1.length(), m = s2.length();

    
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(m + 1, vector<int>(min(n, m) + 1, -1)));

    return helper(s1, s2, n, m, 0, dp);
}

int main() {
    string s1 = "abcdgeagad";
    string s2 = "abcasvabcd";

    cout << "Longest Common Substring Length (Memoization): " << longestCommonSubstring(s1, s2) << endl;

    return 0;
}
