#include <bits/stdc++.h>
using namespace std;

int solve(int n, int r, int end)
{
    vector<vector<int>> dp(n+1, vector<int>(r+1, 0));

    dp[1][1] = 1; // base case

    for (int i = 2; i <= n; i++)
    {
        int total = 0;
        for (int j = 1; j<=r; j++)
            total = total + dp[i-1][j];
        for (int j = 1; j<=r; j++)
            dp[i][j] = total - dp[i-1][j];
    }

    return dp[n][end];
}