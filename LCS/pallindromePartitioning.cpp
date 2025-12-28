#include <bits/stdc++.h>
using namespace std;


// Recursion:
#include <bits/stdc++.h>
using namespace std;

// Function to check if substring s[i..j] is palindrome
bool isPalindrome(string &s, int i, int j) {
    while (i < j) {
        if (s[i] != s[j])
            return false;
        i++;
        j--;
    }
    return true;
}

// Recursive function to find minimum cuts for palindrome partitioning
int minCutsRec(string &s, int start, int end) {
    // Base case: empty substring or single character → no cuts needed
    if (start >= end || isPalindrome(s, start, end)) {
        return 0;
    }

    int minCuts = INT_MAX;

    // Try all possible cuts from start to end-1
    for (int k = start; k < end; k++) {
        if (isPalindrome(s, start, k)) {
            // If s[start..k] is palindrome, cut here and solve for remaining substring
            int cuts = 1 + minCutsRec(s, k + 1, end);
            minCuts = min(minCuts, cuts);
        }
    }

    return minCuts;
}

// int main() {
//     string s = "aab";
//     int n = s.size();
//     cout << "Minimum cuts needed: " << minCutsRec(s, 0, n - 1) << endl;
//     return 0;
// }
// ==========================================================================================================================================

// Pallindrome Partioning:
int minCutPalindrome(string s) {
    int n = s.size();

    // STEP 1: Build palindrome table pal[i][j]
    vector<vector<bool>> pal(n, vector<bool>(n, false));

    for (int len = 1; len <= n; len++) {
        for (int i = 0; i + len - 1 < n; i++) {
            int j = i + len - 1;

            if (len == 1) {
                pal[i][j] = true; // single char
            } 
            else if (len == 2) {
                pal[i][j] = (s[i] == s[j]); // two chars
            } 
            else {
                pal[i][j] = (s[i] == s[j]) && pal[i + 1][j - 1];
            }
        }
    }

    // STEP 2: Build minCuts table
    vector<int> minCuts(n, INT_MAX);

    for (int i = 0; i < n; i++) {
        // If the whole substring s[0..i] is palindrome → no cut needed
        if (pal[0][i]) {
            minCuts[i] = 0;
        } else {
            // try all possible cuts at position k
            for (int k = 0; k < i; k++) {
                if (pal[k + 1][i]) { // right substring is palindrome
                    /*
                    okay so you are saying s the substring formed AFTER the cut (from k+1 to i) a palindrome? 
                    if yes then only that cut will be counted and if we previously had done b|a 
                    for ba and now we have n as pallindrome so have to add that b|a wala 1 plus the 
                    new n wala cut that 1+1=2 in minCut array right
                    */
                    minCuts[i] = min(minCuts[i], minCuts[k] + 1);
                }
            }
        }
    }

    return minCuts[n - 1];
}

int main() {
    string s = "aab";
    cout << "Minimum cuts needed: " << minCutPalindrome(s) << endl;
    return 0;
}
