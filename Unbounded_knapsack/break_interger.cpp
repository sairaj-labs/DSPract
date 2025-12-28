/*
📊 DP TABLE for n = 10
| num | Best break                  | dp[num] |
| --- | --------------------------- | ------- |
| 2   | 1+1 = 1×1                   | **1**   |
| 3   | 1×2=2, 2×1=2                | **2**   |
| 4   | 2×2 = 4                     | **4**   |
| 5   | 2×3 = 6                     | **6**   |
| 6   | 3×3 = 9                     | **9**   |
| 7   | 3×4 = 12                    | **12**  |
| 8   | 3×5 = 15, 2×dp[6]=18 → best | **18**  |
| 9   | 3×6 = 18, 3×dp[6]=27 → best | **27**  |
| 10  | 3×7 = 21, 3×dp[7]=36 → best | **36**  |

watch vedio on this channel for better undersrtanding:
LINK:https://youtu.be/iXtqfIrWMZg?si=U1Q9OVMSOnoDWXwx
*/

#include <bits/stdc++.h>
using namespace std;

int integerBreak(int n) {
    vector<int> dp(n + 1, 0);

    dp[1] = 1; // base (though we won't use n=1 directly)

    for (int num = 2; num <= n; num++) {

        int maxi = 0;

        for (int i = 1; i < num; i++) {
            int noBreak = i * (num - i);
            int yesBreak = i * dp[num - i];

            maxi = max({maxi, noBreak, yesBreak});
        }

        dp[num] = maxi;
    }

    return dp[n];
}

int main() {
    cout << integerBreak(10);  // 36
}
