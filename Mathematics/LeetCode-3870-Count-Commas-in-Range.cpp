// LeetCode 3870 : Count Commas in Range
// Problem Link  : https://leetcode.com/problems/count-commas-in-range/

// Approach 1 (Naive Simulation)
// T.C : O(n)
// S.C : O(1)
class Solution {
public:
    int countCommas(int n) {
        /*
            4-Digits: X,XXX    (1 Comma)
            5-Digits: XX,XXX   (1 Comma)
            6-Digits: XXX,XXX  (1 Comma)
        */
        int result = 0;
        for(int num = 1000; num <= n; num++) {
          result++;
        }
      
        return result;
    }
};

// Approach 2 (Mathematical Observation)
// T.C : O(1)
// S.C : O(1)
class Solution {
public:
    int countCommas(int n) {
        /*
            4-Digits: X,XXX    (1 Comma)
            5-Digits: XX,XXX   (1 Comma)
            6-Digits: XXX,XXX  (1 Comma)
        */
        return max(n-999, 0);
    }
};
