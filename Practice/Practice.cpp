#include<bits/stdc++.h>
using namespace std;
// LCS(Normal):
// int LCS(string&str1,string&str2){
//     int n=str1.length();
//     int m=str2.length();
//     vector<vector<int>>dp(n+1,vector<int>(m+1,0));

//     for(int i=1;i<=n;i++){
//         for(int j=1;j<=m;j++){
//             if(str1[i-1]==str2[j-1]){
//                 dp[i][j]=1+dp[i-1][j-1];
//             }
//             else{
//                 dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
//             }
//         }
//     }
//     return dp[n][m];
// }
// int main(){
//     string s1 = "abcde";
//     string s2 = "ace";
//     cout << LCS(s1, s2);
// }
// =================================================================================================================================================================
// Longest Pallindromic Subsequence:
// int longestPalindromeSubseq(string&str){
//     string t=str;
//     reverse(t.begin(),t.end());

//     int n=str.length();
//     vector<vector<int>>dp(n+1,vector<int>(n+1,0));

//     for(int i=1;i<=n;i++){
//         for(int j=1;j<=n;j++){
//             if(str[i-1]==t[j-1]){
//                 dp[i][j]=1+dp[i-1][j-1];
//             }
//             else{
//                 dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
//             }
//         }
//     }
//     return dp[n][n];
// }
// int main(){
//     string s = "bbabcbcab";
//     cout << longestPalindromeSubseq(s);
// }
// ====================================================================================================================================================================
// Shoretest Common SuperSequence:
// string shortestCommonSupersequence(string&str1,string str2){
//     int n=str1.length();
//     int m=str2.length();

//     vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    

//     for(int i=1;i<=n;i++){
//         for(int j=1;j<=m;j++){
//             if(str1[i-1]==str2[j-1]){
//                 dp[i][j]=1+dp[i-1][j-1];
//             }
//             else{
//                 dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
//             }
//         }
//     }

//     int i=n;
//     int j=m;

//     string result="";
//     while(i>0 || j>0){
//         if(i==0){
//             result+=str2[j-1];
//             j--;
//         }
//         else if(j==0){
//             result+=str1[i-1];
//             i--;
//         }
//         else if(str1[i-1]==str2[j-1]){
//             result+=str1[i-1];
//             i--;
//             j--;
//         }
//         else if(dp[i-1][j]>dp[i][j-1]){
//             result+=str1[i-1];
//             i--;
//         }
//         else{
//             result+=str2[j-2];
//             j--;
//         }
//     }
//     reverse(result.begin(), result.end());
//     return result;
// }
// int main(){
//     // Hard-coded sample input
//     string str1 = "abac";
//     string str2 = "cab";

//     string ans = shortestCommonSupersequence(str1, str2);

//     cout << "SCS = " << ans << endl;

//     return 0;
// }
// =================================================================================================================================================
// Printing LCS:
// string printLCS(string&str1,string&str2){
//     int n=str1.length();
//     int m=str2.length();

//     vector<vector<int>>dp(n+1,vector<int>(m+1,0));

//     for(int i=1;i<=n;i++){
//         for(int j=1;j<=m;j++){
//             if(str1[i-1]==str2[j-1]){
//                 dp[i][j]=1+dp[i-1][j-1];
//             }
//             else{
//                 dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
//             }
//         }
//     }

//     int i=n;
//     int j=m;

//     string result="";

//     while(i>0 || j>0){
//         if(str1[i-1]==str2[j-1]){
//             result+=str1[i-1];
//             i--;
//             j--;
//         }
//         else if(dp[i-1][j]>dp[i][j-1]){
//             i--;
//         }
//         else{
//             j--;
//         }
//     }
//     reverse(result.begin(),result.end());
//     return result;
// }
// int main(){
//     // Hard-coded inputs
//     string a = "abcde";
//     string b = "ace";

//     string ans = printLCS(a, b);

//     cout << "LCS = " << ans << endl;

//     return 0;
// }
// =========================================================================================================================================================================
// Longest Repeating Subsequence:
// string longestRepeatingSubsequence(string&str){
//     int n=str.length();

//     vector<vector<int>>dp(n+1,vector<int>(n+1,0));

//     for(int i=1;i<=n;i++){
//         for(int j=1;j<=n;j++){
//             if(str[i-1]==str[j-1] && i!=j){
//                 dp[i][j]=1+dp[i-1][j-1];
//             }
//             else{
//                 dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
//             }
//         }
//     }

//     int i=n;
//     int j=n;
//     string result="";

//     while(i>0 || j>0){
//         if(str[i-1]==str[j-1] && i!=j){
//             result+=str[i-1];
//             i--;
//             j--;
//         }
//         else if(dp[i-1][j]>dp[i][j-1]){
//             i--;
//         }
//         else{
//             j--;
//         }
//     }
//     reverse(result.begin(),result.end());
//     return result;
// }
// int main(){
//     string s = "aabb";  // hard-coded test

//     string ans = longestRepeatingSubsequence(s);

//     cout << "Longest Repeating Subsequence = " << ans << endl;

//     return 0;
// }
// ========================================================================================================================================================
// Insertions and Deletions:
// int lCM(string &str1,string&str2){
//     int n=str1.length();
//     int m=str2.length();

//     vector<vector<int>>dp(n+1,vector<int>(m+1,0));

//     for(int i=1;i<=n;i++){
//         for(int j=1;j<=m;j++){
//             if(str1[i-1]==str2[j-1]){
//                 dp[i][j]=1+dp[i-1][j-1];
//             }
//             else{
//                 dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
//             }
//         }
//     }
//     return dp[n][m];
// }
// int main(){
//     string str1 = "heap";
//     string str2 = "pea";

//     int lcs=lCM(str1,str2);

//     int deletions=str1.length()-lcs;
//     int insertions=str2.length()-lcs;
    
//     cout<<"Insertions: "<<insertions<<endl;
//     cout<<"Deletions: "<<deletions<<endl;
//     cout<<"Total Operations: "<<insertions+deletions<<endl;
// }
// ==================================================================================================================================================================
// Edit Distance:
// int editDistance(string str1,string str2){
//     int n=str1.length();
//     int m=str2.length();

//     vector<vector<int>>dp(n+1,vector<int>(m+1,0));

//     for(int i=0;i<=n;i++) dp[i][0]=i;
//     for(int j=0;j<=m;j++) dp[0][j]=j;

//     for(int i=1;i<=n;i++){
//         for(int j=1;j<=m;j++){
//             if(str1[i-1]==str2[j-1]){
//                 dp[i][j]=dp[i-1][j-1];
//             }
//             else{
//                 dp[i][j]=1+min(
//                     {
//                     dp[i-1][j],
//                     dp[i][j-1],
//                     dp[i-1][j-1]
//                     }
//                 );
//             }
//         }
//     }
//     return dp[n][m];
// }
// int main(){
//     cout << editDistance("horse", "ros");
// }
// =============================================================================================================================
// Wildcard Pattern Matching:
// int isMatch(string s,string p){
//     int n=s.length();
//     int m=p.length();


//     vector<vector<int>>dp(n+1,vector<int>(m+1,0));
//     // Empty string & empty pattern
//     dp[0][0] = true;
//     for(int j=1;j<=m;j++){
//         if(p[j-1]=='*'){
//             dp[0][j]=dp[0][j-1];
//         }
//     }

//     for(int i=1;i<=n;i++){
//         for(int j=1;j<=m;j++){
//             if(s[i-1]==p[j-1] || p[j-1]=='?'){
//                 dp[i][j]=dp[i-1][j-1];
//             }
//             else if(p[j-1]=='*'){
//                 dp[i][j]=dp[i-1][j] || dp[i][j-1];
//             }
//             else{
//                 dp[i][j]=false;
//             }
//         }
//     }
//     return dp[n][m];
// }
// int main(){
//     string s = "adceb";
//     string p = "*a*b";

//     cout << (isMatch(s, p) ? "MATCH" : "NO MATCH") << endl;

//     return 0;
// }
// ======================================================================================================================================
// Regular Expression Matching:
// bool isMatch(string s,string p){
//     int n=s.length();
//     int m=p.length();
//     vector<vector<int>>dp(n+1,vector<int>(m+1,0));

//     dp[0][0]=true;

//     for(int j=1;j<=m;j++){
//         if(p[j-1]=='*'){
//             dp[0][j]=dp[0][j-2];
//         }
//     }

//     for(int i=1;i<=n;i++){
//         for(int j=1;j<=m;j++){
//             if(s[i-1]==p[j-1] || p[j-1]=='.'){
//                 dp[i][j]=dp[i-1][j-1];
//             }
//             else if(p[j-1]=='*'){
//                 // skip it:
//                 dp[i][j]=dp[i][j-2];

//                 // take it:
//                 if(p[j-2]==s[i-1] || p[j-2]=='.'){
//                     dp[i][j]=dp[i][j] || dp[i-1][j];
//                 }
//             }
//         }
//     }
//     return dp[n][m];
// }
// int main(){
//     string s = "aaab";
//     string p = "a*b";

//     if (isMatch(s, p))
//         cout << "Match\n";
//     else
//         cout << "Not a Match\n";

//     return 0;
// }
// ====================================================================================================================================================================
// Sequence Pattern Matching:
// bool isSubsequence(string s,string t){
//     int n=s.length();
//     int m=t.length();

//     vector<vector<int>>dp(n+1,vector<int>(m+1,0));

//     for(int i=1;i<=n;i++){
//         for(int j=1;j<=m;j++){
//             if(s[i-1]==t[j-1]){
//                 dp[i][j]=dp[i-1][j-1];
//             }
//             else{
//                 dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
//             }
//         }
//     }
//     return dp[n][m]=n;
// }
// int main(){
//     string s = "abc";
//     string t = "ahbgdc";

//     if (isSubsequence(s, t))
//         cout << "s is a subsequence of t\n";
//     else
//         cout << "s is NOT a subsequence of t\n";

//     return 0;
// }
// ====================================================================================================================================================================
// Longest Common Substring:
// int longestCommonSubstring(string s1,string s2){
//     int n=s1.length();
//     int m=s2.length();

//     vector<vector<int>>dp(n+1,vector<int>(m+1,0));

//     int ans=INT_MIN;
//     for(int i=1;i<=n;i++){
//         for(int j=1;j<=m;j++){
//             if(s1[i-1]==s2[j-1]){
//                 dp[i][j]=dp[i-1][j-1]+1;
//                 ans=max(ans,dp[i][j]);
//             }
//             else{
//                 dp[i][j]=0;
//             }
//         }
//     }
//     return ans;
// }
// int main(){
//     string s1 = "abcde";
//     string s2 = "abfce";

//     cout << "Length of Longest Common Substring: " 
//          << longestCommonSubstring(s1, s2) << endl;

//     return 0;
// }
// ===============================================================================================================================================================================
// Count Pallindromic Substring:
// int countPalindromicSubstrings(string s){
//     int n=s.length();

//     vector<vector<bool>>dp(n+1,vector<bool>(n+1,false));

//     int count=0;

//     for(int i=n-1;i>=0;i--){
//         for(int j=i;j<n;j++){
    
//           if(i==j){
//             dp[i][j]=true;
//           }
//           else if(s[i]==s[j]){
//             if(j-i==1) dp[i][j]=true;
//             else dp[i][j]=dp[i+1][j-1];
//           }
//           if(dp[i][j]) count++;
//         }
//     }
//     return count;
// }
// int main(){
//     string s="aaa";
//     cout << "Number of palindromic substrings: " 
//          << countPalindromicSubstrings(s) << endl;

//     return 0;
// }
// ================================================================================================================
// Pallindrome Partitioning:
// int minCutPalindrome(string&s){
//     int n=s.length();
//     vector<vector<int>>dp(n,vector<int>(n,false));
//     int count=0;
//     for(int i=n-1;i>=0;i--){
//         for(int j=i;j<n;j++){
//             if(i==j){
//                 dp[i][j]=true;
//             }
//             else if(s[i]==s[j]){
//                 if(j-i==1) dp[i][j]=true;
//                 else{
//                     dp[i][j]=dp[i+1][j-1];
//                 }
//             }

           
//         }
//     }
    
//     vector<int>minCuts(n,INT_MAX);

//     for(int i=0;i<n;i++){
//         if(dp[0][i]){
//             minCuts[i]=0;
//         }
//         else{
//             for(int k=0;k<i;k++){
//                 if(dp[k+1][i]){
//                     minCuts[i]=min(minCuts[i],minCuts[k]+1);
//                 }
//             }
//         }
//     }
//     return minCuts[n-1];
// }
// int main(){
//     string s = "aab";
//     cout << "Minimum cuts needed: " << minCutPalindrome(s) << endl;
//     return 0;
// }
// ==========================================================================================================================================================================
