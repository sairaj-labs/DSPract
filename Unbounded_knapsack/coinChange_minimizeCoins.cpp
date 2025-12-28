/*
✔ Output Example
For coins = {1,2,5}, target = 11
Best = 5 + 5 + 1 → 3 coins
*/

#include <bits/stdc++.h>
using namespace std;

int minCoins(vector<int>& coins, int target) {
    int n = coins.size();

    vector<vector<int>> dp(n, vector<int>(target + 1, 1e9));

    // Base case: sum 0 requires 0 coins
    // if target=0;
    for (int i = 0; i < n; i++)
        dp[i][0] = 0;

    // Base case: using only first coin
    for (int t = 1; t <= target; t++) {
        if (t % coins[0] == 0)
            dp[0][t] = t / coins[0];
    }

    for (int i = 1; i < n; i++) {
        for (int t = 1; t <= target; t++) {

            int not_take = dp[i - 1][t];

            int take = 1e9;
            if (coins[i] <= t)
                take = 1 + dp[i][t - coins[i]];

            dp[i][t] = min(take, not_take);
        }
    }

    return (dp[n - 1][target] >= 1e9 ? -1 : dp[n - 1][target]);
}

int main() {
    vector<int> coins = {1, 2, 5};
    int target = 11;

    cout << minCoins(coins, target);
}
