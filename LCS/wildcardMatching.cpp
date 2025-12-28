/*
Base case:
🧠 FINAL INTUITION (SUPER EASY)
Think like this:
If pattern is "***" → all stars
→ they can all match nothing
→ empty string matches
→ so dp row is: true true true true
If there is ANY non-* character → match breaks
→ everything after that becomes false
→ like domino effect

Example:
Pattern: "**a*"

DP row:
Pattern	""	*	**	**a	*a
dp[0]	T	T	T	❌	❌
Because the moment 'a' appears, empty string cannot match anymore.
*/
#include <bits/stdc++.h>
using namespace std;

bool isMatch(string s, string p) {
    int n = s.size();
    int m = p.size();

    vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));

    // Empty string & empty pattern
    dp[0][0] = true;

    // Pattern can match empty string only if it is filled with '*'
    for (int j = 1; j <= m; j++) {
        if (p[j - 1] == '*')
            dp[0][j] = dp[0][j - 1];
    }

    // Fill DP
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {

            if (p[j - 1] == s[i - 1] || p[j - 1] == '?') {
                // Characters match OR '?'
                dp[i][j] = dp[i - 1][j - 1];
            }
            else if (p[j - 1] == '*') {
                // '*' can match empty or 1+ characters
                dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
            }
            else {
                dp[i][j] = false;
            }
        }
    }

    return dp[n][m];
}

int main() {
    string s = "adceb";
    string p = "*a*b";

    cout << (isMatch(s, p) ? "MATCH" : "NO MATCH") << endl;

    return 0;
}
