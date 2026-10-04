// LeetCode 678 : Valid Parenthesis String
// Problem Link : https://leetcode.com/problems/valid-parenthesis-string/

// Approach 1 (Naive Recursion)
// T.C : O(3^n) (TLE)
// S.C : O(n)
class Solution {
public:
    int n;

    bool solve(int i, int open, string& s) {
        if(open < 0) return false;
        if(i == n) return open == 0;
        
        if(s[i] == '(') return solve(i+1, open+1, s);
        else if(s[i] == ')') return solve(i+1, open-1, s);
        else {
            bool treatAsOpen  = solve(i+1, open+1, s);
            bool treatAsClose = solve(i+1, open-1, s);
            bool treatAsEmpty = solve(i+1, open, s);

            return treatAsOpen || treatAsClose || treatAsEmpty;
        }
    }

    bool checkValidString(string s) {
        n = s.length();
      
        if(s[n-1] == '(') return false;
        return solve(0, 0, s);    
    }
};

// Approach 2 (Recursion + Memoization)
// T.C : O(n^2)
// S.C : O(n^2)
class Solution {
public:
    int n;
    int dp[101][101];

    bool solve(int i, int open, string& s) {
        if(open < 0) return false;
        if(i == n) return dp[i][open] = (open == 0);
        if(dp[i][open] != -1) return dp[i][open];
        
        if(s[i] == '(') return dp[i][open] = solve(i+1, open+1, s);
        else if(s[i] == ')') return dp[i][open] = solve(i+1, open-1, s);
        else {
            bool treatAsOpen  = solve(i+1, open+1, s);
            bool treatAsClose = solve(i+1, open-1, s);
            bool treatAsEmpty = solve(i+1, open, s);

            return dp[i][open] = treatAsOpen || treatAsClose || treatAsEmpty;
        }
    }

    bool checkValidString(string s) {
        n = s.length();
        
        if(s[n-1] == '(') return false;
        
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, s);    
    }
};
