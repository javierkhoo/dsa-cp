// GFG          : Longest Subsequence with Adjacent Diff as 1
// Problem Link : https://www.geeksforgeeks.org/problems/longest-sub-sequence-such-that-difference-between-adjacents-is-one2558/1

// Approach 1 (Dynamic Programming - Top-Down)
// T.C : O(n^2) (TLE)
// S.C : O(n^2)
class Solution {
  public:
    int n;
    vector<vector<int>> t;
    
    // solve(i, prevIdx) = longest valid subsequence we can construct from arr[i...n-1], given that previous selected index = prevIdx.
    // -1 means nothing has been selected yet.
    //
    // Base Case:
    // solve(n, prevIdx) = 0
    //
    // Recurrence:
    // if(prevIdx == -1 || |arr[i]-arr[prevIdx]| == 1) solve(i, prevIdx) = max(1 + solve(i+1, i), solve(i+1, prevIdx))
    // else solve(i, prevIdx) = solve(i+1, prevIdx)
    //
    // Ans = solve(0, -1).
    int solve(int i, int prevIdx, vector<int>& arr) {
        if(i == n) return 0;
        
        if(t[i][prevIdx+1] != -1)
            return t[i][prevIdx+1];
        
        int take = 0;
        int skip = 0;
        
        if(prevIdx == -1 || abs(arr[i] - arr[prevIdx]) == 1) {
            take = 1 + solve(i+1, i, arr);
        }
        
        skip = solve(i+1, prevIdx, arr);
        
        return t[i][prevIdx+1] = max(take, skip);
    }
    
    int longestSubseq(vector<int>& arr) {
        n = arr.size();
        
        t.assign(n, vector<int>(n+1, -1));
        
        return solve(0, -1, arr);
    }
};

// Approach 2 (Dynamic Programming - Bottom-Up)
// T.C : O(n^2) (TLE)
// S.C : O(n^2)
class Solution {
  public:
    int longestSubseq(vector<int>& arr) {
        int n = arr.size();
        
        // t[i][prevIdx+1] = longest valid subsequence constructed from arr[i...n-1] with previous selected index = prevIdx.
        // -1 means no index was selected previously.
        // Ans = t[0][-1+1] = t[0][0].
        vector<vector<int>> t(n+1, vector<int>(n+1, -1));
        
        // Base Case
        for(int prevIdx = -1; prevIdx <= n-1; prevIdx++) {
            t[n][prevIdx+1] = 0;
        }
        
        // Recurrence (Transition)
        for(int i = n-1; i >= 0; i--) {
            for(int prevIdx = -1; prevIdx < i; prevIdx++) { // only reachable states
                int take = 0;
                int skip = 0;
                
                if(prevIdx == -1 || abs(arr[i]-arr[prevIdx]) == 1) {
                    take = 1 + t[i+1][i+1];
                }
                
                skip = t[i+1][prevIdx+1];
                
                t[i][prevIdx+1] = max(take, skip);
            }
        }
        
        return t[0][0];
    }
};

// Approach 3 (Dynamic Programming - Optimized State)
// T.C : O(n)
// S.C : O(n)
class Solution {
  public:
    int longestSubseq(vector<int>& arr) {
        // dp[x] = longest valid subsequence ending with value x.
        // Ans   = max(dp).
        unordered_map<int, int> dp;
        
        int result = 0;
        
        for(int x : arr) {
            dp[x] = 1 + max(dp[x-1], dp[x+1]);
            result = max(result, dp[x]);
        }
        
        return result;
    }
};
