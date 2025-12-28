/*
🔹 Intuition
Think of the DP table like this:
Base case:
|    | "" | r | o | s |
| -- | -- | - | - | - |
| "" | 0  | 1 | 2 | 3 |
| h  | 1  |   |   |   |
| o  | 2  |   |   |   |
| r  | 3  |   |   |   |
| s  | 4  |   |   |   |
| e  | 5  |   |   |   |
First row: source is empty → insert all target characters
First column: target is empty → delete all source characters
Everything else (i>0, j>0) is filled using insert, delete, replace logic.
*/
#include <bits/stdc++.h>
using namespace std;

int editDistance(string s1, string s2) {
    int n = s1.size();
    int m = s2.size();

    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    // Base cases
    for(int i = 0; i <= n; i++) dp[i][0] = i;     // delete all
    for(int j = 0; j <= m; j++) dp[0][j] = j;     // insert all

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {

            if(s1[i-1] == s2[j-1]) {
                dp[i][j] = dp[i-1][j-1];
            }
            else {
                dp[i][j] = 1 + min({
                    dp[i][j-1],    // insert
                    dp[i-1][j],    // delete
                    dp[i-1][j-1]   // replace
                });
            }
        }
    }

    return dp[n][m];
}

int main() {
    cout << editDistance("horse", "ros");
}
