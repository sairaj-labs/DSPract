/*
Input: n = 4
Output: 5
Explanation:
1+1+1+1  
1+1+2  
1+2+1  
2+1+1  
2+2

*/

#include<bits/stdc++.h>
using namespace std;
int climbingStairsTabulation(int n){
    vector<int>dp(n+1,0);

    dp[1]=1;
    dp[2]=2;

    for(int i=3;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[n];
}
int main(){
    int n=4;
    cout<<climbingStairsTabulation(n)<<endl;
    return 0;
}