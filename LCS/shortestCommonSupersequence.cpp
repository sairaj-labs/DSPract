/*
⭐ Shortest Common Supersequence (SCS)

Goal:
Given two strings s1 and s2, find the shortest possible string
that contains BOTH s1 and s2 as subsequences.

Example:
s1 = "abac"
s2 = "cab"

One valid SCS = "cabac"
It contains:
  - "abac"  → c-a-b-a-c
  - "cab"   → c-a-b
Length = 5

🔑 Key Idea:
SCS = Combine both strings but
      DO NOT repeat the characters that are part of LCS.

So first find LCS → then build SCS from it.
*/

#include <bits/stdc++.h>
using namespace std;

// Function to compute the Shortest Common Supersequence
string shortestCommonSupersequence(string str1, string str2) {

    int len1 = str1.size();
    int len2 = str2.size();

    /*
    -------------------------------------------------------
    STEP 1: Build the LCS DP TABLE (length only)
    dp[i][j] = length of LCS between:
               str1[0...i-1] and str2[0...j-1]
    -------------------------------------------------------
    */

    vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));

    // Fill DP table bottom-up
    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {

            // If characters match → part of LCS
            if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } 
            // If they don't match → take best possible LCS
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    /*
    -------------------------------------------------------
    STEP 2: Reconstruct the SCS using the DP table
    We backtrack like LCS, BUT:
      - We add ALL characters (not just matches)
      - But matching characters are added ONLY ONCE
    -------------------------------------------------------
    */

    int i = len1, j = len2;
    string result = "";

    while (i > 0 || j > 0) {

        // If str1 is exhausted → must take from str2
        if (i == 0) {
            result += str2[j - 1];
            j--;
        }

        // If str2 is exhausted → must take from str1
        else if (j == 0) {
            result += str1[i - 1];
            i--;
        }

        // Characters match → include ONCE (essential part of SCS)
        else if (str1[i - 1] == str2[j - 1]) {
            result += str1[i - 1];
            i--;
            j--;
        }

        // Characters don’t match → follow the LCS direction
        // Take the character from the direction where LCS was larger
        else if (dp[i - 1][j] > dp[i][j - 1]) {
            result += str1[i - 1];
            i--;
        } 
        else {
            result += str2[j - 1];
            j--;
        }
    }

    // Since we built SCS backwards, reverse it
    reverse(result.begin(), result.end());
    return result;
}

int main() {

    // Hard-coded sample input
    string str1 = "abac";
    string str2 = "cab";

    string ans = shortestCommonSupersequence(str1, str2);

    cout << "SCS = " << ans << endl;

    return 0;
}
