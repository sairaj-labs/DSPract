/*
✔ Example
Coins = {1,2,3}, Target = 4
Ways:
1+1+1+1
1+1+2
2+2
1+3
Total = 4 ways
*/
#include <bits/stdc++.h>
using namespace std;

long long countWays(vector<int>& coins, int target) {
    int n = coins.size();
    
    // dp[i][t] = number of ways to make sum t using coins[0..i]
    vector<vector<long long>> dp(n, vector<long long>(target + 1, 0));

    // Base case: If target is 0 → 1 way (choose nothing)
    for (int i = 0; i < n; i++)
        dp[i][0] = 1;

    // Base case: For the first coin (index 0)
    for (int t = 0; t <= target; t++) {
        if (t % coins[0] == 0)
            dp[0][t] = 1;
    }

    // Fill DP table
    for (int i = 1; i < n; i++) {
        for (int t = 1; t <= target; t++) {

            long long not_take = dp[i - 1][t];

            long long take = 0;
            if (coins[i] <= t)
                take = dp[i][t - coins[i]]; // stay on same index for unbounded

            dp[i][t] = take + not_take;
        }
    }

    return dp[n - 1][target];
}

// MEMOIZATION SOLUTION:
// dp[index][target] = number of ways to make "target" using coins[0..index]
long long dp[1001][1001];

long long solve(int index, int target, vector<int>& coins) {
    // Base case: if target becomes 0 → 1 valid way
    if (target == 0) return 1;

    // If no coins left but target > 0 → 0 ways
    if (index == 0) {
        // Only coin[0] can be used
        return (target % coins[0] == 0) ? 1 : 0;
    }

    // Memo check
    if (dp[index][target] != -1)
        return dp[index][target];

    long long take = 0;
    if (coins[index] <= target) {
        // Unbounded → stay on same index
        take = solve(index, target - coins[index], coins);
    }

    long long not_take = solve(index - 1, target, coins);

    return dp[index][target] = take + not_take;
}

long long countWaysMemoization(vector<int>& coins, int target) {
    memset(dp, -1, sizeof(dp));
    return solve(coins.size() - 1, target, coins);
}
int main() {
    vector<int> coins = {1, 2, 3};
    int target = 4;

    cout << countWays(coins, target);  
    // Output: 4
}
