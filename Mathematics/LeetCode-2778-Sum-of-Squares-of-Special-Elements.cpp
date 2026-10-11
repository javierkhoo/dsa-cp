// LeetCode 2778 : Sum of Squares of Special Elements
// Problem Link  : https://leetcode.com/problems/sum-of-squares-of-special-elements/

// Approach 1 (Enumeration)
// T.C : O(n)
// S.C : O(1)
class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int n = nums.size();

        int result = 0;
        for(int i = 0; i < n; i++) {
            if(n % (i+1) == 0) {
              result += nums[i]*nums[i];
            }
        }

        return result;
    }
};

// Approach 2 (Number Theory - Divisor Pairs)
// T.C : O(√n)
// S.C : O(1)
// Intuition:
//     If d|n, then n/d|n.
//     Thus, divisors occur in pairs (d, n/d).
//
//     At least one divisor in each pair must be <= √n.
//     Supposed otherwise:
//       d > √n ∧ n/d > √n
//     Then:
//       d * n/d > n, but d * n/d = n
//     Their product exceeds n, contradiction!
//
//     Hence, it suffices to enumerate divisors up to √n to identify all divisor pairs (d, n/d).
class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int n = nums.size();

        int result = 0;
        for(int i = 0; (i+1)*(i+1) <= n; i++) {
            if(n % (i+1) == 0) {
                result += nums[i]*nums[i];
              
                if(n/(i+1) != i+1) { // avoid double-counting when the two divisors are equal
                    result += nums[n/(i+1) - 1]*nums[n/(i+1) - 1];
                }
            }
        }

        return result;
    }
};
