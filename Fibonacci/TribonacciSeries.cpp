/*
Input: n = 4
Output: 4
Explanation: 2 + 1 + 1 = 4
*/
#include<bits/stdc++.h>
using namespace std;
int tribonacci(int n) {
    if (n == 0) return 0;
    if (n == 1 || n == 2) return 1;

    vector<long long> dp(n+1, 0);
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 1;

    for (int i = 3; i <= n; i++) {
        dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
    }

    return dp[n];
}
int main(){
    int n=4;
    cout<<tribonacci(n)<<endl;
    return 0;
}