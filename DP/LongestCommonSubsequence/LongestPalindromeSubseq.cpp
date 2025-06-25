#include<iostream>
#include<vector>
using namespace std;

/*
Return the length of the longest palindromic subsequence in the given string
*/

int longestPalindromeSubseq(string s)
{
    string rev;
    int n = s.size();
    for (int i = 0; i < n; i++)
    {
        rev += s[n - i - 1];
    }
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < n + 1; j++)
        {
            if (s[i - 1] == rev[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[n][n];
}

int main(){
    string s = "bbbab";
    cout << longestPalindromeSubseq(s);
    return 0;
}