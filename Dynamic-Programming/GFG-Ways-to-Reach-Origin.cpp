// GFG          : Ways to Reach Origin
// Problem Link : https://www.geeksforgeeks.org/problems/paths-to-reach-origin3850/1

/*
  solve(i,j) returns number of distinct paths to reach (0,0) from (i,j) with each move decreasing i or j by 1.
  
  Transition:
    solve(i,j) = solve(i-1,j) + solve(i,j-1)
  
  Base Cases:
    solve(0,0) = 1
    solve(i,j) = 0 if i < 0 or j < 0
  
  Answer:
    solve(x,y)
*/

// Approach 1 (Naive DFS) (TLE)
// T.C : O(2^(x+y))
// S.C : O(x+y)
class Solution {
public:  
    int MOD = 1e9 + 7;

    // dfs(i,j) = number of distinct paths to reach (0,0) from (i,j) with each move decreasing i or j by 1.
    int dfs(int i, int j) {
        if(i == 0 && j == 0) return 1;
        if(i < 0 || j < 0) return 0;
        
        int left = dfs(i-1, j);
        int down = dfs(i, j-1);
        
        return (left + down) % MOD;
    }
    
    int ways(int x, int y) {
        if(x < 0 || y < 0) return 0;
        return dfs(x, y);
    }
};

// Approach 2 (Top-Down DP)
// T.C : O(xy)
// S.C : O(xy)
class Solution {
public:  
    int MOD = 1e9 + 7;
    int dp[501][501];
    
    int solve(int i, int j) {
        if(i == 0 && j == 0) return 1;
        if(i < 0 || j < 0) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int left = solve(i-1, j);
        int down = solve(i, j-1);
        
        return dp[i][j] = (left + down) % MOD;
    }
    
    int ways(int x, int y) {
        if(x < 0 || y < 0) return 0;
        
        memset(dp, -1, sizeof(dp));
        return solve(x, y);    
    }
};

// Approach 3 (Bottom-Up DP)
// T.C : O(xy)
// S.C : O(xy)
class Solution {
public:
    int ways(int x, int y) {
        const int MOD = 1e9 + 7;
      
        int dp[501][501]{};
        dp[0][0] = 1;
        
        for(int i = 0; i <= x; i++) {
            for(int j = 0; j <= y; j++) {
                if(i == 0 && j == 0) continue;
                
                if(i-1 >= 0) dp[i][j] += dp[i-1][j];
                if(j-1 >= 0) dp[i][j] += dp[i][j-1];
                
                dp[i][j] %= MOD;
            }
        }
        
        return dp[x][y];
    }
};

// Approach 4 (Bottom-Up DP + Rolling Array)
// T.C : O(xy)
// S.C : O(y)
class Solution {
public:
    int ways(int x, int y) {
        const int MOD = 1e9 + 7;
        
        vector<int> dp(y+1, 0);
        dp[0] = 1;
        
        for(int i = 0; i <= x; i++) {
            for(int j = 1; j <= y; j++) {
                dp[j] = (dp[j] + dp[j-1]) % MOD;
            }
        }
        
        return dp[y];
    }
};
