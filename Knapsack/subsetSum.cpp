#include<bits/stdc++.h>
using namespace std;
bool helperMemoization(int index,int target,vector<int>&arr,vector<vector<int>>&dp){
    if(target==0) return true;

    if(index==0){
        return arr[0]==target;
    }

    if(dp[index][target]!=-1){
        return dp[index][target];
    }

    bool notpick=helperMemoization(index-1,target,arr,dp);
    bool pick=false;
    if(arr[index]<=target){
        pick=helperMemoization(index-1,target-arr[index],arr,dp);
    }
    return dp[index][target]=(pick|| notpick);
}
bool helperTabulation(int target,vector<int>&arr){
    int n=arr.size();
     vector<vector<int>>dp(n,vector<int>(target+1,0));

    //  if target==0;
     for(int i=0;i<n;i++){
        dp[i][0]=true;
     }

    //  if only single element
     if(arr[0]<=target){
        dp[0][arr[0]]=true;
     }

     for(int i=1;i<n;i++){
        for(int t=1;t<=target;t++){
            bool notpick=dp[i-1][t];

            bool pick=false;
            if(arr[i]<=target){
                pick=dp[i-1][t-arr[i]];
            }

            dp[i][t]=pick || notpick;
        }
     }
     return dp[n-1][target];
}
int main(){
    vector<int> arr = {3, 2, 5, 7};
    int target = 10;
    int n=arr.size();
    vector<vector<int>>dp(n,vector<int>(target+1,-1));

    cout<<(helperMemoization(n-1,target,arr,dp)?"YES":"NO")<<endl;
    cout<<(helperTabulation(target,arr)?"YES":"NO")<<endl;
     return 0;
}