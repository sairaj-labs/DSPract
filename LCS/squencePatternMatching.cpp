/*
🔹 Example
s = "abc"
t = "ahbgdc"
Compute LCS(s, t):
LCS("abc", "ahbgdc") = "abc" → length 3
s.size() = 3 → matches → subsequence exists
*/
#include <bits/stdc++.h>
using namespace std;

bool isSubsequence(string s, string t) {
    int n = s.size();
    int m = t.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    // Build LCS table
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s[i - 1] == t[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    return dp[n][m] == n; // true if LCS length equals s.size()
}

int main() {
    string s = "abc";
    string t = "ahbgdc";

    if (isSubsequence(s, t))
        cout << "s is a subsequence of t\n";
    else
        cout << "s is NOT a subsequence of t\n";

    return 0;
}
