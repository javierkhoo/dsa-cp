// LeetCode 131 : Palindrome Partitioning
// Problem Link : https://leetcode.com/problems/palindrome-partitioning/

// Approach 1 (Backtracking + Naive Palindrome Check)
// T.C : O(2^n * n)
// S.C : O(n)
class Solution {
public:  
    int n;
    vector<vector<string>> result;

    bool isPalindrome(int l, int r, string& s) {
        while(l < r) {
            if(s[l] != s[r]) return false;
            l++;
            r--;
        }
        return true;
    }

    // backtrack(i, curr) generates all valid palindrome partitions of the suffix s[i...n-1],
    // while curr stores the partial partition chosen for s[0...i-1].
    void backtrack(int i, vector<string>& curr, string& s) {
        if(i == n) {
            result.push_back(curr);
            return;
        }

        for(int partition = i; partition < n; partition++) {
            if(isPalindrome(i, partition, s)) { // O(n)
                curr.push_back(s.substr(i, partition-i+1));
                backtrack(partition+1, curr, s);
                curr.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        n = s.length();

        vector<string> curr;
        backtrack(0, curr, s);
        
        return result;    
    }
};

// Approach 2 (Backtracking + Palindrome DP)
// T.C : O(2^n * n)
// S.C : O(n^2)
class Solution {
public:
    int n;
    vector<vector<string>> result;
    vector<vector<bool>> isPalindrome;

    // backtrack(i, curr) generates all valid palindrome partitions of the suffix s[i...n-1],
    // while curr stores the partial partition chosen for s[0...i-1].
    void backtrack(int i, vector<string>& curr, string& s) {
        if(i == n) {
            result.push_back(curr);
            return;
        }

        for(int partition = i; partition < n; partition++) {
            if(isPalindrome[i][partition]) { // O(1)
                curr.push_back(s.substr(i, partition-i+1));
                backtrack(partition+1, curr, s);
                curr.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        n = s.length();

        isPalindrome.assign(n, vector<bool>(n, false));
        for(int len = 1; len <= n; len++) {
            for(int i = 0; i <= n-len; i++) {
                int j = i + len - 1;

                if(len == 1) {
                    isPalindrome[i][j] = true;
                } else if(len == 2) {
                    isPalindrome[i][j] = s[i] == s[j];
                } else {
                    isPalindrome[i][j] = (s[i] == s[j]) && isPalindrome[i+1][j-1];
                }
            }
        }

        vector<string> curr;
        backtrack(0, curr, s);
        
        return result;    
    }
};
