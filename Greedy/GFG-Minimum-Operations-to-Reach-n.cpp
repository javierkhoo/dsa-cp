// GFG          : Minimum Operations to Reach n (similar to LeetCode 2139 Minimum Moves to Reach Target Score)
// Problem Link : https://www.geeksforgeeks.org/problems/find-optimum-operation4504/1

// Approach 1a (Greedy)
// T.C : O(logn)
// S.C : O(1)
//
// Intuition:
//     Work backwards from n to 0 by reversing the allowed operations.
//       - If n is odd, subtract 1,
//       - Otherwise, divide by 2.
//     These choices are optimal and eliminate the need to explore multiple possibilities.
class Solution {
public:
    int minOperation(int n) {
        int result = 0;
      
        while(n > 0) {
            if(n % 2 == 0) n /= 2;
            else n--;
            result++;
        }
        
        return result;
    }
};

// Approach 1b (Greedy - Recursive Implementation)
// T.C : O(logn)
// S.C : O(logn)
class Solution {
public:
    // solve(i) = minimum operations required to reach 0 from i using the reversed operations.
    int solve(int i) {
        if(i == 0) return 0;

        if(i % 2 == 0) {
            return 1 + solve(i/2);
        } else {
            return 1 + solve(i-1);
        }
    }

    int minOperation(int n) {
        return solve(n);
    }
};

// Approach 2 (Top-Down DP - Forward Thinking)
// T.C : O(n)
// S.C : O(n)
class Solution {
public:
    vector<int> dp;

    // solve(i) = minimum operations required to reach n from i.
    //
    // Transition:
    //     solve(i) = 1 + min(solve(i+1), solve(i*2)) considering only valid transitions.
    //
    // Base Case:
    //     solve(n) = 0
    //
    // Answer:
    //     solve(0)
    int solve(int i, int n) {
        if(i == n) return 0;
        if(dp[i] != -1) return dp[i];
        
        int result = 1 + solve(i+1, n);
        
        if(i > 0 && i*2 <= n) { // i <= n/2 to avoid integer overflow
            result = min(result, 1 + solve(i*2, n));
        }
        
        return dp[i] = result;
    }
    
    int minOperation(int n) {
        dp.assign(n+1, -1);
        return solve(0, n);
    }
};

// Approach 3 (Bottom-Up DP - Forward Thinking)
// T.C : O(n)
// S.C : O(n)
class Solution {
public:
    int minOperation(int n) {
        // dp[i] = minimum operations required to reach n from i.
        //
        // Transition:
        //     dp[i] = 1 + min(dp[i+1], dp[i*2]), considering only valid transitions.
        //
        // Base Case:
        //     dp[n] = 0
        //
        // Answer:
        //     dp[0]
        vector<int> dp(n+1, 0);
      
        for(int i = n-1; i >= 0; i--) {
            dp[i] = 1 + dp[i+1];
          
            if(i > 0 && i*2 <= n) { // i <= n/2 to avoid integer overflow
              dp[i] = min(dp[i], 1 + dp[i*2]);
            }
        }
        
        return dp[0];
    }
};

// Approach 4 (Top-Down DP - Backward Thinking)
// T.C : O(n)
// S.C : O(n)
class Solution {
public:
    vector<int> dp;
    
    // solve(i) = minimum operations required to reach i from 0.
    //
    // Transition:
    //     solve(i) = 1 + min(solve(i-1), solve(i/2)), considering only valid transitions.
    //
    // Base Case:
    //     solve(0) = 0
    //
    // Answer:
    //     solve(n)
    int solve(int i) {
        if(i == 0) return 0;
        if(dp[i] != -1) return dp[i];
        
        int result = 1 + solve(i-1);
        
        if(i % 2 == 0) {
            result = min(result, 1 + solve(i/2));
        }
        
        return dp[i] = result;
    }
    
    int minOperation(int n) {
        dp.assign(n+1, -1);
        return solve(n);
    }
};

// Approach 5 (Bottom-Up DP - Backward Thinking)
// T.C : O(n)
// S.C : O(n)
class Solution {
public:
    int minOperation(int n) {
        // dp[i] = minimum operations required to reach i from 0.
        //
        // Transition:
        //     dp[i] = 1 + min(dp[i-1], dp[i/2]), considering only valid transitions.
        //
        // Base Case:
        //     dp[0] = 0
        //
        // Answer:
        //     dp[n]
        vector<int> dp(n+1, 0);
        
        for(int i = 1; i <= n; i++) {
            dp[i] = 1 + dp[i-1];
            
            if(i % 2 == 0) {
                dp[i] = min(dp[i], 1 + dp[i/2]);
            }
        }
        
        return dp[n];
    }
};
