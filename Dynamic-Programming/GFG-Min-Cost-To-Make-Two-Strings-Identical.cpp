// GFG          : Min Cost To Make Two Strings Identical
// Problem Link : https://www.geeksforgeeks.org/problems/minimum-cost-to-make-two-strings-identical1107/1

/*
  Intuition:
    At index i and j of s1 and s2 respectively,
      - If s1[i] == s2[j], we save our deletions and recurse on s1[i+1...m-1] and s2[j+1...n-1].
      - Otherwise, we have two choices:
        1. Delete s1[i], recurse on s1[i+1...m-1] and s2[j...n-1].
        2. Delete s2[j], recurse on s1[i...m-1] and s2[j+1...n-1].
    
  - State:
    dp[i][j] = minimum cost to make s1[i...m-1] and s2[j...n-1] equal.
  
  - Recurrence:
    dp[i][j] = dp[i+1][j+1]                                  , if s1[i] == s2[j]
             = min(costS1 + dp[i+1][j], costS2 + dp[i][j+1]) , otherwise
             
  - Base Cases:
    dp[i][j] = costS2*(n-j) , if i == m
             = costS1*(m-i) , if j == n
  
  - Answer:
    dp[0][0].
*/

// Approach 1 (Top-Down DP)
// T.C : O(mn)
// S.C : O(mn)
class Solution {
public:
    int m;
    int n;
    int c1;
    int c2;
    
    int dp[1001][1001];
    
    // solve(i,j) = minimum cost to make s1[i...] and s2[j...] equal
    int solve(int i, int j, string& s1, string& s2) {
        if(i == m) return c2*(n-j);
        if(j == n) return c1*(m-i);
        if(dp[i][j] != -1) return dp[i][j];
        
        if(s1[i] == s2[j]) return dp[i][j] = solve(i+1, j+1, s1, s2);
        
        int deleteS1 = c1 + solve(i+1, j, s1, s2);
        int deleteS2 = c2 + solve(i, j+1, s1, s2);
        
        return dp[i][j] = min(deleteS1, deleteS2);
    }
    
    int findMinCost(string &s1, string &s2, int costS1, int costS2) {
        m  = s1.length();
        n  = s2.length();
        c1 = costS1;
        c2 = costS2;
        
        memset(dp, -1, sizeof(dp));
        
        return solve(0, 0, s1, s2);
    }
};

// Approach 2 (Bottom-Up DP)
// T.C : O(mn)
// S.C : O(mn)
class Solution {
public:
    int findMinCost(string &s1, string &s2, int costS1, int costS2) {
        int m = s1.length();
        int n = s2.length();
        
        // dp[i][j] = min cost to make s1[i...] and s2[j...] equal
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        
        // Base Case
        for(int j = 0; j <= n; j++) dp[m][j] = costS2*(n-j);
        for(int i = 0; i <= m; i++) dp[i][n] = costS1*(m-i);
        
        // Recurrence
        for(int i = m-1; i >= 0; i--) {
            for(int j = n-1; j >= 0; j--) {
                if(s1[i] == s2[j]) {
                    dp[i][j] = dp[i+1][j+1];
                } else {
                    int deleteS1 = costS1 + dp[i+1][j];
                    int deleteS2 = costS2 + dp[i][j+1];
                    
                    dp[i][j] = min(deleteS1, deleteS2);
                }
            }
        }
        
        return dp[0][0];
    }
};
