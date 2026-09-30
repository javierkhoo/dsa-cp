// LeetCode 1111 : Maximum Nesting Depth of Two Valid Parentheses Strings
// Problem Link  : https://leetcode.com/problems/maximum-nesting-depth-of-two-valid-parentheses-strings/

/*
  Intuition:
    The nesting depth of a parenthesis is its current balance level.
    To minimize the maximum depth of the two resulting VPSs, assign consecutive nesting levels alternately to the two groups.

    Hence, parentheses at odd depths go to one group and those at even depths go to the other.
    This splits the original maximum depth roughly in half.

    A matching '(' and ')' belong to the same depth, so they must be assigned to the same group.
*/

// Approach (Greedy)
// T.C : O(n)
// S.C : O(1)
class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int n = seq.length();

        vector<int> result(n);

        int depth = 0;
        for(int i = 0; i < n; i++) {
            char ch = seq[i];

            if(ch == '(') {
                depth++;
                result[i] = (depth % 2 == 0) ? 1 : 0;
            } else {
                result[i] = (depth % 2 == 0) ? 1 : 0;
                depth--;
            }
        }

        return result;
    }
};
