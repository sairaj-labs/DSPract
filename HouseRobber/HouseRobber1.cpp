/*
✅ 1. What is House Robber I? (LeetCode 198)
You are a thief.
You are given an array nums where:
nums[i] = amount of money in the i-th house.
You cannot rob two adjacent houses (police system will catch you).
You want to maximize the money you rob.
Example
nums = [2, 7, 9, 3, 1]
You cannot pick adjacent houses.
Best choice → pick 2, 9, 1 = 12
OR pick 7, 3, 1 = 11
Maximum = 12
*/
#include<bits/stdc++.h>
using namespace std;
// Recursive Solution:
int robFrom(int i, vector<int>& nums) {
    // If index goes outside array => no money
    if (i >= nums.size()) return 0;

    // Option 1: rob this house
    int rob = nums[i] + robFrom(i + 2, nums);

    // Option 2: skip this house
    int skip = robFrom(i + 1, nums);

    return max(rob, skip);
}

int rob(vector<int>& nums) {
    return robFrom(0, nums);
}

// ==================================================================================================================================================
// Dp solution:
int robTabulation(vector<int>& nums) {
    int n = nums.size();
    if (n == 1) return nums[0];

    vector<int> dp(n, 0);

    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);

    for (int i = 2; i < n; i++) {
        int rob = nums[i] + dp[i-2];
        int skip = dp[i-1];
        dp[i] = max(rob, skip);
    }

    return dp[n-1];
}
int main(){
    vector<int>nums={2,7,9,3,1};
    cout<<robTabulation(nums);
    return 0;
}

















/*
DRY RUN:
Great! Let’s build the **DP table for House Robber I** with a clear, easy example.

I’ll take the classic input:

```
nums = [2, 7, 9, 3, 1]
```

We will fill DP **from right to left** because:

```
dp[i] = max( nums[i] + dp[i+2], dp[i+1] )
```

To avoid out-of-bounds issues, we create:

```
dp size = n + 2 = 5 + 2 = 7
dp = [0, 0, 0, 0, 0, 0, 0]
indexes = 0  1  2  3  4  5  6
nums indexes = 0 1 2 3 4
```

Let’s fill it step-by-step **from i = 4 → 0**.

---

# ✅ **Step-by-step DP table building**

---

## **i = 4** (nums[4] = 1)

```
rob  = nums[4] + dp[6] = 1 + 0 = 1
skip = dp[5]           = 0

dp[4] = max(1, 0) = 1
```

DP now:

```
i:   0  1  2  3  4  5  6
dp: [0, 0, 0, 0, 1, 0, 0]
```

---

## **i = 3** (nums[3] = 3)

```
rob  = 3 + dp[5] = 3 + 0 = 3
skip = dp[4]     = 1

dp[3] = max(3, 1) = 3
```

DP now:

```
dp: [0, 0, 0, 3, 1, 0, 0]
```

---

## **i = 2** (nums[2] = 9)

```
rob  = 9 + dp[4] = 9 + 1 = 10
skip = dp[3]     = 3

dp[2] = max(10, 3) = 10
```

DP now:

```
dp: [0, 0, 10, 3, 1, 0, 0]
```

---

## **i = 1** (nums[1] = 7)

```
rob  = 7 + dp[3] = 7 + 3 = 10
skip = dp[2]     = 10

dp[1] = max(10, 10) = 10
```

DP now:

```
dp: [0, 10, 10, 3, 1, 0, 0]
```

---

## **i = 0** (nums[0] = 2)

```
rob  = 2 + dp[2] = 2 + 10 = 12
skip = dp[1]     = 10

dp[0] = max(12, 10) = 12
```

Final DP:

```
dp: [12, 10, 10, 3, 1, 0, 0]
```

---

# 🎉 Final Answer = `dp[0] = 12`

---

# 🔥 Summary Table (clean view)

```
nums = [2, 7, 9, 3, 1]

Index:   0   1   2   3   4
Value:   2   7   9   3   1

dp:
i     |   dp[i]   |   Explanation
----------------------------------------------
4     |     1      | max(1 + 0, 0) = 1
3     |     3      | max(3 + 0, 1) = 3
2     |    10      | max(9 + 1, 3) = 10
1     |    10      | max(7 + 3, 10) = 10
0     |    12      | max(2 + 10, 10) = 12
```

---

# Want a visual diagram with arrows?

Or want the same for **memoization**, **space-optimized DP**, or **House Robber II**?

*/