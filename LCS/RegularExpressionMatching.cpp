#include <bits/stdc++.h>
using namespace std;

// Recursive:
bool solve(string &s, string &p, int i, int j) {

    // Case 1: both strings fully matched
    if (i == s.size() && j == p.size())
        return true;

    // Pattern finished, but string not finished → cannot match
    if (j == p.size())
        return false;

    // Check if current characters match
    bool firstMatch = (i < s.size() &&
                      (s[i] == p[j] || p[j] == '.'));

    // Case 2: If next pattern character is '*'
    if (j + 1 < p.size() && p[j + 1] == '*') {

        // Option 1: Skip "x*" (zero occurrences)
        bool skipStar = solve(s, p, i, j + 2);

        // Option 2: Consume one character from string IF it matches
        bool consumeStar = false;
        if (firstMatch) {
            consumeStar = solve(s, p, i + 1, j);
        }

        return skipStar || consumeStar;
    }

    // Case 3: No '*', normal match required
    if (firstMatch)
        return solve(s, p, i + 1, j + 1);

    return false;
}

bool isMatch(string s, string p) {
    return solve(s, p, 0, 0);
}

int main() {
    string s = "aaab";
    string p = "a*b";

    if (isMatch(s, p))
        cout << "Match\n";
    else
        cout << "Not a Match\n";

    return 0;
}

// ======================================================================================================================================================

// Memoization:
vector<vector<int>> memo; // -1 = uncomputed, 0 = false, 1 = true
bool solve(int i, int j, string &s, string &p) {
        // memoized value exists
        if (memo[i][j] != -1) return memo[i][j];

        // If pattern finished → match only if string also finished
        if (j == p.size()) 
            return memo[i][j] = (i == s.size());

        // Check if first characters match (for this position)
        bool firstMatch = (i < s.size() &&
                           (s[i] == p[j] || p[j] == '.'));

        // Case 1: If next character in pattern is '*'
        if (j + 1 < p.size() && p[j + 1] == '*') {
            // Two options:

            // 1) Skip the "x*" completely
            bool skipStar = solve(i, j + 2, s, p);

            // 2) Use "*" to match one character (only if firstMatch)
            bool useStar = false;
            if (firstMatch)
                useStar = solve(i + 1, j, s, p);

            return memo[i][j] = (skipStar || useStar);
        }

        // Case 2: No star → must match one character
        if (firstMatch)
            return memo[i][j] = solve(i + 1, j + 1, s, p);

        return memo[i][j] = false;
}

bool isMatch(string s, string p) {
        memo.assign(s.size() + 1, vector<int>(p.size() + 1, -1));
        return solve(0, 0, s, p);
}

// =========================================================================================================================================================

// Tabulation Approach:
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();

        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));

        dp[0][0] = true;

        // Handle patterns like a*, a*b*, a*b*c* at empty string
        for (int j = 2; j <= m; j++) {
            if (p[j - 1] == '*')
                dp[0][j] = dp[0][j - 2];
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {

                // Case 1: direct match or '.'
                if (p[j - 1] == s[i - 1] || p[j - 1] == '.') {
                    dp[i][j] = dp[i - 1][j - 1];
                }

                // Case 2: '*'
                else if (p[j - 1] == '*') {
                    // Option 1: skip char before '*'
                    dp[i][j] = dp[i][j - 2];

                    // Option 2: use '*' for one or more characters
                    if (p[j - 2] == s[i - 1] || p[j - 2] == '.') {
                        dp[i][j] = dp[i][j] || dp[i - 1][j];
                    }
                }
            }
        }

        return dp[n][m];
    }
};

