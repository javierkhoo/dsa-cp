// LeetCode 301 : Remove Invalid Parentheses
// Problem Link : https://leetcode.com/problems/remove-invalid-parentheses/

// Approach 2 (Optimized Backtracking)
// Let n = s.length(),
//     p = number of parentheses,
//     K = number of distinct optimal answers,
//     L = length of each optimal answer.
//
// T.C : O(2^p * n)
// S.C : O(n + KL) for recursion/current path + final output,
//       O(2^p * n) worst-case including temporary stored candidates.
class Solution {
public:
    int n;
    int maxLen;
    unordered_set<string> st;

    void backtrack(int i, int balance, string& curr, string& s) {
        if(balance < 0 || curr.length() + (n-i) < maxLen) return; // early pruning

        if(i == n) {
            if(balance == 0) {
                if(curr.length() > maxLen) {
                    maxLen = curr.length();
                    st.clear();
                    st.insert(curr); // O(maxLen)
                } else if(curr.length() == maxLen) {
                    st.insert(curr); // O(maxLen)
                }
            }
            return;  
        }

        if(isalpha(s[i])) {
            curr.push_back(s[i]);
            backtrack(i+1, balance, curr, s);
            curr.pop_back();
            return;
        }

        curr.push_back(s[i]);
        backtrack(i+1, balance + ((s[i] == '(') ? 1 : -1), curr, s);
        curr.pop_back();
        backtrack(i+1, balance, curr, s);
    }

    vector<string> removeInvalidParentheses(string s) {
        n = s.length();
        maxLen = 0;
        st.clear();

        string curr;
        backtrack(0, 0, curr, s);

        return vector<string>(st.begin(), st.end());    
    }
};
