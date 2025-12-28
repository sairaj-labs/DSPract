#include<bits/stdc++.h>
using namespace std;
vector<int> LIS(vector<int>& arr) {
    int n = arr.size();
    vector<int> dp(n, 1), parent(n, -1);

    int best = 1, lastIndex = 0;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if(arr[j] < arr[i] && dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1;
                parent[i] = j;
            }
        }
        if(dp[i] > best) {
            best = dp[i];
            lastIndex = i;
        }
    }

    // reconstruct path
    vector<int> lis;
    while(lastIndex != -1) {
        lis.push_back(arr[lastIndex]);
        lastIndex = parent[lastIndex];
    }
    reverse(lis.begin(), lis.end());
    return lis;
}
int main(){
    vector<int>arr={10, 9, 2, 5, 3, 7};
    vector<int>ans=LIS(arr);
    for(auto num:ans){
        cout<<num<<" ";
    }
    return 0;
}


/*
Absolutely — let’s do a **full dry run** of the entire code **step-by-step** using a small array so everything is crystal clear.

---

# 🔥 Array for Dry Run

Let’s use:

```
arr = [10, 22, 9, 33]
```

Indexes:

```
 0   1   2   3
10  22   9  33
```

---

# 🔹 STEP 1 — Initialize

```
dp     = [1, 1, 1, 1]
parent = [-1, -1, -1, -1]
best = 1
lastIndex = 0
```

---

# 🔹 STEP 2 — Start DP loops

---

# ⭐ i = 0 → arr[0] = 10

Inner loop does nothing (no j < 0)

Check best:

```
dp[0] = 1 > best(1)? NO
```

State:

```
dp     = [1, 1, 1, 1]
parent = [-1, -1, -1, -1]
```

---

# ⭐ i = 1 → arr[1] = 22

Check j = 0

```
arr[0] < arr[1]   → 10 < 22  → TRUE
```

Check if can improve dp[1]:

```
dp[0] + 1 = 1 + 1 = 2
dp[1] = 1
2 > 1 → YES → UPDATE
```

So:

```
dp[1] = 2
parent[1] = 0
```

Check if new best:

```
dp[1] = 2 > best(1) → YES
best = 2
lastIndex = 1
```

State:

```
dp     = [1, 2, 1, 1]
parent = [-1, 0, -1, -1]
best = 2
lastIndex = 1
```

LIS ending at index 1:
→ 10 → 22

---

# ⭐ i = 2 → arr[2] = 9

Check j = 0

```
10 < 9 ? NO
```

Check j = 1

```
22 < 9 ? NO
```

dp[2] stays 1
parent[2] stays -1

Check best:

```
1 > 2 ? NO
```

State unchanged:

```
dp     = [1, 2, 1, 1]
parent = [-1, 0, -1, -1]
best = 2
lastIndex = 1
```

---

# ⭐ i = 3 → arr[3] = 33

### Check j = 0

```
10 < 33 → TRUE
dp
```

Update:

```
dp[3] = 2
parent[3] = 0
```

---

### Check j = 1

```
22 < 33 → TRUE
dp
```

Update:

```
dp[3] = 3
parent[3] = 1
```

---

### Check j = 2

```
9 < 33 → TRUE
dp? NO
```

No update.

---

Check best:

```
dp[3] = 3 > best(2) → YES
best = 3
lastIndex = 3
```

State:

```
dp     = [1, 2, 1, 3]
parent = [-1, 0, -1, 1]
best = 3
lastIndex = 3
```

---

# 🔥 Parent chain now represents the LIS:

```
lastIndex = 3 → parent[3] = 1 → parent[1] = 0 → parent[0] = -1
```

Meaning:

```
33 ← 22 ← 10
```

---

# 🔹 STEP 3 — Reconstruct LIS

Start:

```
lastIndex = 3
lis = []
```

### iteration 1:

```
push arr[3] = 33
lastIndex = parent[3] = 1
```

lis = `[33]`

### iteration 2:

```
push arr[1] = 22
lastIndex = parent[1] = 0
```

lis = `[33, 22]`

### iteration 3:

```
push arr[0] = 10
lastIndex = parent[0] = -1
```

lis = `[33, 22, 10]`

Stop loop.

Now reverse:

Final LIS:

```
[10, 22, 33]
```

---

# 🎯 Final Output For This Array

```
LIS length = 3
LIS sequence = [10, 22, 33]
```

---

# Want another dry run?

I can dry run:

✔️ The parent & dp build
✔️ A larger or trickier example
✔️ An array you choose

Just tell me the array!

*/