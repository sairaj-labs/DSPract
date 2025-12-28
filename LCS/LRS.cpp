#include <bits/stdc++.h>
using namespace std;

string longestRepeatingSubsequence(string s) {
    int n = s.size();

    // DP table
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    // Build DP  
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (s[i - 1] == s[j - 1] && i != j) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    // Reconstruct LRS
    int i = n, j = n;
    string result = "";

    while (i > 0 && j > 0) {

        // matched AND different indices
        if (s[i - 1] == s[j - 1] && i != j) {
            result += s[i - 1];
            i--;
            j--;
        }
        else {
            if (dp[i - 1][j] > dp[i][j - 1])
                i--;
            else
                j--;
        }
    }

    reverse(result.begin(), result.end());
    return result;
}

int main() {
    string s = "aabb";  // hard-coded test

    string ans = longestRepeatingSubsequence(s);

    cout << "Longest Repeating Subsequence = " << ans << endl;

    return 0;
}
