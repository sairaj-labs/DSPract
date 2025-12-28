#include <bits/stdc++.h>
using namespace std;

int longestCommonSubstring(string s1, string s2) {
    int n = s1.size();
    int m = s2.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    int ans = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                ans = max(ans, dp[i][j]); // track max length
            } else {
                dp[i][j] = 0; // substring must be contiguous
            }
        }
    }

    return ans;
}

int main() {
    string s1 = "abcde";
    string s2 = "abfce";

    cout << "Length of Longest Common Substring: " 
         << longestCommonSubstring(s1, s2) << endl;

    return 0;
}
