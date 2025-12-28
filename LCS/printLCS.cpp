#include <bits/stdc++.h>
using namespace std;

string printLCS(string a, string b) {
    int n = a.size();
    int m = b.size();

    // Step 1: Build DP table for LCS length
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i - 1] == b[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    // Step 2: Reconstruct LCS by backtracking
    int i = n, j = m;
    string lcs = "";

    while (i > 0 && j > 0) {
        if (a[i - 1] == b[j - 1]) {
            // matched char (diagonal move)
            lcs += a[i - 1];
            i--;
            j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--; // move UP
        }
        else {
            j--; // move LEFT
        }
    }

    // reverse because we built it backwards
    reverse(lcs.begin(), lcs.end());
    return lcs;
}

int main() {
    // Hard-coded inputs
    string a = "abcde";
    string b = "ace";

    string ans = printLCS(a, b);

    cout << "LCS = " << ans << endl;

    return 0;
}
