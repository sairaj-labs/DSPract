/*
n🔥 Max Sum Without Adjacent in a Circular Array
(Also called House Robber II, Circular Stickers, Circular Maximum Sum of Non-Adjacent Elements)
✅ 1. Problem Explanation
You are given a circular array:
nums = [a, b, c, d, e]
In a circular array:
index 0 is adjacent to index n-1
So you cannot pick both:
nums[0] AND nums[n-1]
Everything else is the same rule:
You can’t pick adjacent elements.
❗ Main Trick (VERY IMPORTANT)
Because the array is circular, we cannot use the normal DP directly.
So we break the problem into 2 linear cases:
🎯 Case 1: Exclude the last element
Take the array:
[0 ... n-2]
Meaning we allow picking nums[0], but we forbid nums[n-1].
🎯 Case 2: Exclude the first element
Take the array:
[1 ... n-1]
Meaning we allow picking nums[n-1], but forbid nums[0].
🔥 Why is this valid?
Because for circular adjacency:
If you include nums[0], you must exclude nums[n-1]
If you include nums[n-1], you must exclude nums[0]
So we check both possible worlds.
Then take the maximum.
*/

#include<bits/stdc++.h>
using namespace std;
int robLinear(vector<int>& arr) {
    int n = arr.size();
    if (n == 0) return 0;
    if (n == 1) return arr[0];

    vector<int> dp(n, 0);
    dp[0] = arr[0];
    dp[1] = max(arr[0], arr[1]);

    for (int i = 2; i < n; i++) {
        dp[i] = max(arr[i] + dp[i - 2], dp[i - 1]);
    }
    return dp[n - 1];
}
int robCircular(vector<int>& nums) {
    int n = nums.size();
    if (n == 1) return nums[0];

    // CASE 1: Exclude last element
    vector<int> case1(nums.begin(), nums.end() - 1);

    // CASE 2: Exclude first element
    vector<int> case2(nums.begin() + 1, nums.end());

    return max(robLinear(case1), robLinear(case2));
}
int main(){
    vector<int>nums={2,3,2};
    cout<<robCircular(nums)<<endl;
    return 0;
}