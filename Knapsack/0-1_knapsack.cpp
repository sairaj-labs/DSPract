#include<bits/stdc++.h>
using namespace std;
int helperRecursion(int index,int W,vector<int>&wt,vector<int>&val){
    // base case:
    if(index==0){
        if(wt[0]<=W) return val[0];
        return 0;
    }

    // option 1 :Do not take item:
    int notTake=helperRecursion(index-1,W,wt,val);

    // option 2: take the item:

    int take=0;

    if(wt[index]<=W){
        take=val[index]+helperRecursion(index-1,W-wt[index],wt,val);
    }
    return max(take,notTake);
}
int helperTabulation(vector<int>&wt,vector<int>&val,int W){
    int n=wt.size();
    vector<vector<int>>dp(n,vector<int>(W+1,0));

    // base case:index=0;

    for(int w=0;w<=W;w++){
        if(wt[0]<=W)  dp[0][w]=val[0];
    }

    for(int i=1;i<n;i++){
        for(int w=0;w<=W;w++){
            int notTake=dp[i-1][w];

            int take=0;

            if(wt[i]<=w){
                take=val[i]+dp[i-1][w-wt[i]];
            }
            dp[i][w]=max(take,notTake);
        }
    }
    return dp[n-1][W];
}
int main(){
    vector<int>wt={1,2,4,5};
    vector<int>value={5,4,8,6};
    int capacity=5;
    int n=wt.size();
    int ans=helperRecursion(n-1,capacity,wt,value);
    int newans=helperTabulation(wt,value,capacity);
    cout<<ans<<endl;
    cout<<newans<<endl;
    return 0;
}