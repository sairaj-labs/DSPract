/*
📌 Example Dry Run

Let arr = [10, 9, 2, 5, 3, 7]

Initial:

dp = [1,1,1,1,1,1]
ans = 1

i = 0 → dp[0] = 1

ans = 1

i = 1 → (9)

Check j = 0 → (10 < 9? No)
dp[1] = 1
ans = 1

i = 2 → (2)

Check j = 0 → (10 < 2? No)
Check j = 1 → (9 < 2? No)
dp[2] = 1
ans = 1

i = 3 → (5)

Check j = 0 → No
Check j = 1 → No
Check j = 2 → (2 < 5) → dp[3] = dp[2] + 1 = 2
ans = 2

i = 4 → (3)

Check j = 2 → (2 < 3) → dp[4] = 2
ans = 2

i = 5 → (7)

Check j = 2 → (2 < 7) → dp[5] = 2
Check j = 3 → (5 < 7) → dp[5] = 3
Check j = 4 → (3 < 7) → dp[5] = 3
ans = 3

Final dp:

[1, 1, 1, 2, 2, 3]


Final answer:

3
*/
#include<bits/stdc++.h>
using namespace std;
int lengthOfLIS(vector<int>& arr) {
    int n = arr.size();
    vector<int> dp(n, 1);

    int ans = 1;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if(arr[j] < arr[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        ans = max(ans, dp[i]);
    }
    return ans;
}
int main(){
    vector<int>arr={10, 9, 2, 5, 3, 7};
    cout<<lengthOfLIS(arr);
}

/*
🔥 WHY “max” is REQUIRED?

Because there are multiple j values before i.

Each j gives a different possible LIS ending at i.

You must choose the best possible LIS among all of them.

🧠 Example that breaks without max

arr:

[10, 22, 9, 33]


We compute dp:

Start:

dp = [1,1,1,1]

i = 3 → value = 33

Possible j values:

j=0: (10 < 33)

LIS ending here becomes 1 + 1 = 2
so dp[3] = 2

j=1: (22 < 33)

LIS ending here becomes 2 + 1 = 3
so dp[3] = max(2, 3) = 3

j=2: (9 < 33)

LIS ending here becomes 1 + 1 = 2
so dp[3] = max(3, 2) = 3 (still 3)

Final:

dp[3] = 3

❌ If you do dp[i] = dp[j] + 1 directly, look what happens:

j=0 → dp[3] = 2
j=1 → dp[3] = 3
j=2 → dp[3] = 2 ❌ OVERRIDES BEST VALUE

Final dp becomes:

dp[3] = 2   ❌ WRONG


You lose the correct LIS value because a smaller dp[j] came later and overwrote it.
*/
