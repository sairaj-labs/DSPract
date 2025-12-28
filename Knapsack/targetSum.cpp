#include<bits/stdc++.h>
using namespace std;

int targetSum(vector<int>&arr,int target,int sum,int reqSum){
    // check for odd sum:
    if((sum + target) % 2 != 0) return 0;

    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(reqSum + 1, 0));

    // Base case: sum 0 is always possible (empty subset)
    for(int i = 0; i < n; i++){
        dp[i][0] = 1;
    }

    // Single element case
    if(arr[0] <= reqSum){
        dp[0][arr[0]] = 1;
    }

    for(int i = 1; i < n; i++){
        for(int t = 1; t <= reqSum; t++){
            int notPick = dp[i - 1][t];

            int pick = 0;
            if(arr[i] <= t){
                pick = dp[i - 1][t - arr[i]];
            }

            dp[i][t] = pick + notPick;
        }
    }
    return dp[n - 1][reqSum];
}

int main(){
    vector<int> arr = {1,1,1,1,1};
    int target = 3;
    int sum = accumulate(arr.begin(), arr.end(), 0);
    int reqSum = (target + sum) / 2;

    cout << targetSum(arr, target, sum, reqSum) << endl;
}
