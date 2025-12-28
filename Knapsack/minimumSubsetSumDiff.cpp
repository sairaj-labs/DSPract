#include <bits/stdc++.h>
using namespace std;

int minSubsetSumDiff(vector<int>& arr) {
    int n = arr.size();
    int total = accumulate(arr.begin(), arr.end(), 0);

    int k = total / 2; // we check upto S/2

    vector<vector<bool>> dp(n, vector<bool>(k + 1, false));

    // Base Case
    for(int i = 0; i < n; i++)
        dp[i][0] = true;

    if (arr[0] <= k)
        dp[0][arr[0]] = true;

    // Fill DP
    for(int i = 1; i < n; i++){
        for(int t = 1; t <= k; t++){

            bool notPick = dp[i - 1][t];
            bool pick = false;

            if(arr[i] <= t)
                pick = dp[i - 1][t - arr[i]];

            dp[i][t] = pick || notPick;
        }
    }

    // Find closest sum to total/2
    int s1 = 0;
    for(int t = k; t >= 0; t--){
        if (dp[n - 1][t]) {
            s1 = t;
            break;
        }
    }

    int s2 = total - s1;
    return abs(s2 - s1);
}

int main() {
    vector<int> arr = {1, 6, 11, 5};
    cout << minSubsetSumDiff(arr) << endl;  // Output: 1
}
