/*
Problem Definition

Given an array arr of length n and a number d, pick elements such that any two picked elements are at least distance d apart.
Return the maximum sum achievable.

Example:

arr = [3, 2, 5, 10, 7], d = 2
Possible picks:
- Pick indices 0 and 2: sum = 3 + 5 = 8
- Pick indices 0 and 3: sum = 3 + 10 = 13
- Pick indices 2 and 4: sum = 5 + 7 = 12
Answer = 13
*/
#include <bits/stdc++.h>
using namespace std;

// Recursive brute-force
int maxSumRecursive(vector<int>& arr, int index, int d) {
    if (index >= arr.size()) return 0;

    // Option 1: pick current element, skip next d-1
    int pick = arr[index] + maxSumRecursive(arr, index + d, d);
    // Option 2: skip current element
    int skip = maxSumRecursive(arr, index + 1, d);

    return max(pick, skip);
}

// Tabulation:
int maxSumForwardDP(vector<int>& arr, int d) {
    int n = arr.size();
    vector<int> dp(n, 0); // dp[i] = max sum up to index i

    for (int i = 0; i < n; i++) {
        // Option 1: pick arr[i]
        int pick = arr[i];
        if (i - d >= 0) pick += dp[i - d]; // add max sum from valid previous element

        // Option 2: skip arr[i]
        int skip = (i > 0) ? dp[i - 1] : 0;

        dp[i] = max(pick, skip);
    }

    return dp[n - 1]; // max sum considering all elements
}

int main() {
    vector<int> arr = {3, 2, 5, 10, 7};
    int d = 2;
    cout << maxSumForwardDP(arr, d) << endl; // Output: 13
    return 0;
}
