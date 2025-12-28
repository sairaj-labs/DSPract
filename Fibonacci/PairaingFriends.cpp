/*

*/
#include<bits/stdc++.h>
using namespace std;
int pairingFriendsTabulation(int n){
    vector<long long>dp(n+1,0);
    if(n<=2) return n;

    dp[1]=1;
    dp[2]=2;

    for(int i=3;i<=n;i++){
        dp[i]=dp[i-1]+(long long )(i-1)*dp[i-2];
    }
    return dp[n];
}
int main(){
    int n=4;
    cout<<pairingFriendsTabulation(n)<<endl;
    return 0;
}