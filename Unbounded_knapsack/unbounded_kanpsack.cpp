#include<bits/stdc++.h>
using namespace std;
int unbounded_kanpsackTabulation(vector<int>&wt,vector<int>&val,int W){
    int n= wt.size();

    vector<vector<int>>dp(n,vector<int>(W+1,0));

    for(int w=0;w<=W;w++){
        dp[0][w]=(w/wt[0])*val[0];
    }

    for(int i=1;i<n;i++){
        for(int w=0;w<=W;w++){

            int notTake=dp[i-1][w];

            int take=INT_MIN;
            if(wt[i]<=w){
                take=val[i]+dp[i][w-wt[i]];
            }
            dp[i][w]=max(take,notTake);
        }
    }
    return dp[n-1][W];
}
int main(){
    vector<int>wt={2,4,6};
    vector<int>val={5,11,13};
    int W=10;

    int ans=unbounded_kanpsackTabulation(wt,val,W);
    cout<<ans<<endl;
    return 0;
}