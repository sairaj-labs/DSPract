// go for algomonster explanation
#include <bits/stdc++.h>
using namespace std;

vector<int> stones;
vector<vector<int>> dp;
unordered_map<int, int> stoneToIndex;
int n;

// Simple DFS function
bool dfs(int currentIndex, int lastJump) {
    if (currentIndex == n - 1)
        return true;

    if (dp[currentIndex][lastJump] != -1)
        return dp[currentIndex][lastJump];

    for (int nextJump = lastJump - 1; nextJump <= lastJump + 1; nextJump++) {
        if (nextJump > 0) {
            int nextPos = stones[currentIndex] + nextJump;

            if (stoneToIndex.count(nextPos)) {
                int nextIndex = stoneToIndex[nextPos];
                if (dfs(nextIndex, nextJump))
                    return dp[currentIndex][lastJump] = 1;
            }
        }
    }

    return dp[currentIndex][lastJump] = 0;
}

bool canCross(vector<int>& stonesInput) {
    stones = stonesInput;
    n = stones.size();

    dp.assign(n, vector<int>(n, -1));
    stoneToIndex.clear();

    for (int i = 0; i < n; i++)
        stoneToIndex[stones[i]] = i;

    return dfs(0, 0);
}

int main() {

    // 🔥 Hard-coded input
    // Example: LeetCode test case
    vector<int> stonesInput = {0, 1, 3, 5, 6, 8, 12, 17};

    bool ans = canCross(stonesInput);

    cout << (ans ? "YES\n" : "NO\n");

    return 0;
}
