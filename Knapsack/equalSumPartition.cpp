#include<bits/stdc++.h>
using namespace std;
bool canPartition(vector<int>&arr,int target,int sum){
    // check for odd sum:
    if(sum % 2 != 0) return false;

    int n = arr.size();
    vector<vector<bool>> dp(n, vector<bool>(target+1,false));

    // if target==0:
    for(int i=0;i<n;i++){
        dp[i][0]=true;
    }

    // if single element:
    if(arr[0]<=target){
        dp[0][arr[0]]=true;
    }

    for(int i=1;i<n;i++){
        for(int t=1;t<=target;t++){
            int notPick=dp[i-1][t];

            int pick=false;
            if(arr[i]<=t){
                pick=dp[i-1][t-arr[i]];
            }
            dp[i][t]=pick || notPick;
        }
    }
    return dp[n-1][target];
}
int main(){
    vector<int>arr={1,5,11,5};
    int sum=accumulate(arr.begin(),arr.end(),0);
    int target=sum/2;
    cout << (canPartition(arr,target,sum) ? "YES" : "NO");
}