/*
🔹 DP Formula
For substring s[i..j] (len > 2):
dp[i][j] = (s[i] == s[j]) && dp[i+1][j-1]
- Ends must match (s[i] == s[j])
- Inner substring must be palindrome (dp[i+1][j-1])
🔹 Examples
- "abcba" → ends 'a'=='a', inner "bcb" palindrome → ✅ palindrome
- "abca" → ends 'a'=='a', inner "bc" not palindrome → ❌ not palindrome
*/

#include <bits/stdc++.h>
using namespace std;

int countPalindromicSubstrings(string s) {
    int n = s.size();
    vector<vector<bool>> dp(n, vector<bool>(n, false));
    int count = 0;

    for (int i = n - 1; i >= 0; i--) {         // start index (reverse to fill dp[i+1][j-1] first)
        for (int j = i; j < n; j++) {          // end index

            if (i == j) {
                dp[i][j] = true;               // single char
            }
            else if (s[i] == s[j]) {
                if (j - i == 1) dp[i][j] = true;       // length 2
                else dp[i][j] = dp[i+1][j-1];          // longer
            }

            if (dp[i][j]) count++;
        }
    }

    return count;
}
int main() {
    string s = "aaa";
    cout << "Number of palindromic substrings: " 
         << countPalindromicSubstrings(s) << endl;

    return 0;
}
