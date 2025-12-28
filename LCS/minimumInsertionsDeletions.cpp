/*
✅ Problem Statement
Given two strings:
str1
str2
You must find:
Minimum deletions + minimum insertions
to convert str1 → str2

Allowed operations:
Delete a character from str1
Insert a character into str1
💡 No substitutions allowed.
🎯 Key DP Idea

The only part of str1 that does NOT need to be changed is the LCS (Longest Common Subsequence).
Everything else must be:
Deleted if extra in str1
Inserted if missing from str2
🧠 Formula
Let:
n = str1.length()
m = str2.length()
lcs = LCS(str1, str2)

Then:
Minimum Deletions  = n - lcs
Minimum Insertions = m - lcs
Total = (n - lcs) + (m - lcs)

📌 Example
str1 = "heap"
str2 = "pea"
Step 1 → Find LCS:
LCS = "ea" → length = 2
Compute operations:
Deletions  = 4 - 2 = 2
Insertions = 3 - 2 = 1
Total = 3 operations
This matches the optimal answer.
*/
#include <bits/stdc++.h>
using namespace std;

// LCS function
int LCS(const string &s1, const string &s2) {
    int n = s1.size();
    int m = s2.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[n][m];
}

int main() {
    string str1 = "heap";
    string str2 = "pea";

    int lcs = LCS(str1, str2);

    int deletions = str1.size() - lcs;
    int insertions = str2.size() - lcs;

    cout << "Minimum Deletions: " << deletions << endl;
    cout << "Minimum Insertions: " << insertions << endl;
    cout << "Total Operations: " << deletions + insertions << endl;

    return 0;
}
