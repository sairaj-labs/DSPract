#include <bits/stdc++.h>
using namespace std;

/*
🎯 The key difference is this:
In House Robber, input is the houses:
nums = [a, b, c, d, ...]
So for two houses (index 0 and 1), you choose the max one:
dp[1] = max(nums[0], nums[1])
Because you can rob either house 0 or house 1.
⭐ But in Delete and Earn:
Your houses are not nums
They are points array [0..maxVal].
And points[0] = 0 ALWAYS.
Why?
Because there is no number "0" in nums.
If you delete "0", you earn 0 points.
So:
points = [0, something, something,...]
So when initializing dp:
dp[0] = points[0] = 0
dp[1] = points[1]   <-- no need to take max(0, points[1])
Because:
max(points[0], points[1]) = max(0, points[1]) = points[1]
So writing:
dp[1] = points[1];
is simply writing the answer directly.
*/


int deleteAndEarn(vector<int>& nums) {
    if (nums.empty()) return 0;

    int maxVal = *max_element(nums.begin(), nums.end());

    vector<int> points(maxVal + 1, 0);

    // Step 1: accumulate total points for each number
    for (int x : nums) {
        points[x] += x;
    }

    // Step 2: House Robber DP
    vector<int> dp(maxVal + 1, 0);

    dp[0] = 0;
    dp[1] = points[1];

    for (int i = 2; i <= maxVal; i++) {
        int pick = points[i] + dp[i - 2];
        int skip = dp[i - 1];
        dp[i] = max(pick, skip);
    }

    return dp[maxVal];
}

int main() {
    vector<int> nums = {3, 4, 2};

    cout << "Maximum points: " << deleteAndEarn(nums) << endl;

    return 0;
}


/*
Let's run the **same 3-step transformation** for:

```cpp
vector<int> nums = {3, 4, 2};
```

Super clean and slow dry-run so your brain gets it perfectly.

---

# ✅ Step 1: Find max value

```cpp
int maxVal = *max_element(nums.begin(), nums.end());
```

nums = {3, 4, 2}

So:

```
maxVal = 4
```

---

# ✅ Step 2: Create points array

```cpp
vector<int> points(maxVal + 1, 0);
```

This becomes:

```
index:  0  1  2  3  4
points: 0  0  0  0  0
```

---

# ✅ Step 3: Fill points using nums

Code:

```cpp
for (int x : nums) {
    points[x] += x;
}
```

Let's dry run **one element at a time**.

---

### 🔸 First element: x = 3

```
points[3] += 3
points becomes:
index:  0  1  2  3  4
points: 0  0  0  3  0
```

---

### 🔸 Second element: x = 4

```
points[4] += 4
points becomes:
index:  0  1  2  3  4
points: 0  0  0  3  4
```

---

### 🔸 Third element: x = 2

```
points[2] += 2
points becomes:
index:  0  1  2  3  4
points: 0  0  2  3  4
```

---

# 🎯 Final points array

```
index:  0  1  2  3  4
points: 0  0  2  3  4
```

Meaning:

* If you delete **2**, you get **2**
* If you delete **3**, you get **3**
* If you delete **4**, you get **4**

---

# 🧠 How this maps to the "rob" DP

Now the problem becomes:

> Choose values from `points` (0..4), but if you take index `i`, you cannot take `i-1` or `i+1`.

So it becomes:

```
points = [0, 0, 2, 3, 4]
           |  |  |  |  |
           0  1  2  3  4 <-- number value
```

House Robber on this array.

Let me know if you want full dry run of DP also.

*/
