#include<bits/stdc++.h>
using namespace std;
int countSubsetofSumTabulation(vector<int>&arr,int target){
    int n=arr.size();
    vector<vector<int>>dp(n,vector<int>(target+1,0));

    for(int i=0;i<n;i++){
        dp[i][0]=1;
    }

    if(arr[0]<=target){
        dp[0][arr[0]]=1;
    }

    for(int i=1;i<n;i++){
        for(int sum=1;sum<=target;sum++){
            int notpick=dp[i-1][sum];

            int pick=0;
            if(arr[i]<=target){
                pick=dp[i-1][sum-arr[i]];
            }
            dp[i][sum]=pick+notpick;
        }
    }
    return dp[n-1][target];
}
int main(){
    vector<int>arr={2,3,5};
    int target=5;
    int ans=countSubsetofSumTabulation(arr,target);
    cout<<"The Count is: "<<ans<<endl;
    return 0;
}