// GFG          : Max Adjacent Diffs Sum with 1 Replacements
// Problem Link : https://www.geeksforgeeks.org/problems/modify-array-to-maximize-sum-of-adjacent-differences1729/1

// Approach 1 (Dynamic Programming - Top-Down)
// T.C : O(2n) = O(n)
// S.C : O(2n) = O(n)
class Solution {
  public:
    int n;
    vector<vector<int>> t;
    
    // solve(i, prev) = max. sum of abs. diff. from index i onwards,
    // given the choice made for index i-1.
    //
    // prev = 0 -> arr[i-1] was kept as arr[i-1]
    // prev = 1 -> arr[i-1] was changed to 1
    //
    // Therefore,
    // prevVal = (prev == 0) ? arr[i-1] : 1
    //
    // Transition:
    // solve(i, prev) = max(
    //     |arr[i] - prevVal| + solve(i+1, 0),
    //     |1 - prevVal|      + solve(i+1, 1)
    // )
    //
    // Answer: max(solve(1, 0), solve(1, 1)).
    int solve(int i, int prev, vector<int>& arr) {
        if(i == n) return 0;
        if(t[i][prev] != -1) return t[i][prev];
        
        int prevVal = (prev == 0) ? arr[i-1] : 1;
        
        int keep = abs(arr[i]-prevVal) + solve(i+1, 0, arr);
        int change = abs(1-prevVal) + solve(i+1, 1, arr);
        
        return t[i][prev] = max(keep, change);
    }
    
    int maxDiffSum(vector<int>& arr) {
        n = arr.size();
        
        t.assign(n, vector<int>(2, -1));
        
        return max(solve(1, 0, arr), // arr[0] = arr[0]
                   solve(1, 1, arr)); // arr[0] = 1
    }
};

// Approach 2 (Dynamic Programming - Bottom-Up)
// T.C : O(2n) = O(n)
// S.C : O(2n) = O(n)
class Solution {
  public:
    int maxDiffSum(vector<int>& arr) {
        int n = arr.size();
        
        // t[i][prev] = max. sum. of abs. diff. from index i onwards,
        // given the choice made for index i-1.
        //
        // prev = 0 -> arr[i-1] was kept as arr[i-1]
        // prev = 1 -> arr[i-1] was changed to 1
        //
        // Therefore,
        // prevVal = (prev == 0) ? arr[i-1] : 1
        //
        // Transition:
        // t[i][prev] = max(|arr[i]-prevVal| + t[i+1][0],
        //                  |1-prevVal|      + t[i+1][1]
        //                 )
        //
        // Answer = max(t[1][0], t[1][1]).
        vector<vector<int>> t(n+1, vector<int>(2, -1));
        
        // Base Case
        t[n][0] = t[n][1] = 0;
        
        // Recurrence
        for(int i = n-1; i >= 1; i--) {
            for(int prev = 0; prev <= 1; prev++) {
                int prevVal = (prev == 0) ? arr[i-1] : 1;
                
                int keep    = abs(arr[i]-prevVal) + t[i+1][0];
                int change  = abs(1-prevVal) + t[i+1][1];
                
                t[i][prev] = max(keep, change);
            }
        }
        
        return max(t[1][0], t[1][1]);
    }
};
