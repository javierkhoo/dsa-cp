// LeetCode 1541 : Minimum Insertions to Balance a Parentheses String
// Problem Link  : https://leetcode.com/problems/minimum-insertions-to-balance-a-parentheses-string/

// Approach (Greedy)
// T.C : O(n)
// S.C : O(1)
class Solution {
public:
    int minInsertions(string s) {
        int n = s.length();

        int balance = 0;
        int result  = 0;

        int i = 0;
        // Loop Invariant:
        // After each iteration, all processed ')' are matched, and balance counts the remaining unmatched '('.
        while(i < n) {
            if(s[i] == '(') {
                balance++;
                i++;
            } else {
                if(i+1 < n && s[i+1] == ')') {
                    i += 2;
                } else {
                    result++; // add ')'
                    i++;
                }

                if(balance > 0) {
                    balance--;
                } else {
                    result++; // add '('
                }   
            }
        }

        return result + 2*balance;
    }
};
