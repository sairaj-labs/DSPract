/*
🟧 Dry Run Example

price = [2, 5, 7, 8], N = 5
Length choices: 1,2,3,4

Try combinations:
1+1+1+1+1 → value = 10
2+3 → value = 5 + 7 = 12
2+2+1 → 5+5+2 = 12
3+1+1 → 7 + 4 = 11
4+1 → 8 + 2 = 10
Best is 12
DP returns → 12

table:
| i (piece length) | L=0 | L=1 | L=2 | L=3 | L=4 | L=5 |
| ---------------- | --- | --- | --- | --- | --- | --- |
| 1                | 0   | 2   | 4   | 6   | 8   | 10  |
| 2                | 0   | 2   | 5   | 7   | 10  | 12  |
| 3                | 0   | 2   | 5   | 7   | 10  | 12  |
| 4                | 0   | 2   | 5   | 7   | 10  | 12  |
| 5                | 0   | 2   | 5   | 7   | 10  | 12  |

*/
#include<bits/stdc++.h>
using namespace std;
int rodCuttingTabulation(vector<int>&prices,int length){
        vector<int>len(length);
        for(int i=0;i<length;i++){
            len[i]=i+1;
            // len={1,2,3,4,5}
        }

        vector<vector<int>>dp(length,vector<int>(length+1,0));

        // If onyl one length:
        for(int l=0;l<=length;l++){
            dp[0][l]=l*prices[0];
        }

        for(int i=1;i<length;i++){
            for(int l=0;l<=length;l++){
                int notPick=dp[i-1][l];

                int pick=INT_MIN;
                if(len[i]<=l){
                    pick=prices[i]+dp[i-1][l-len[i]];
                }
                dp[i][l]=max(pick,notPick);
            }
        }
        return dp[length-1][length];
}
int main(){
    vector<int>prices={2, 5, 7, 8, 10};
    int length=5;
    int ans=rodCuttingTabulation(prices,length);
    cout<<ans<<endl;
    return 0;
}