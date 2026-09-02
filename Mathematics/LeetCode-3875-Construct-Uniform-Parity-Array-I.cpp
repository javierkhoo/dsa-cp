// LeetCode 3875 : Construct Uniform Parity Array I
// Problem Link  : https://leetcode.com/problems/construct-uniform-parity-array-i/

// Approach (Mathematical Observation)

/*
  Every x in nums1 is either odd or even.

  Case 1: All x in nums1 are even.
  --------------------------------
  Then, we can simply take every x and we are done.

  Case 2: At least one x in nums1 is odd.
  ---------------------------------------
  Then, for every x in nums1:
    - If x is odd, we take it directly.
    - Otherwise, x is even. Since there is at least one odd element,
      we can subtract that odd element from x, and even - odd = odd.

  Hence, in both cases, we can always make every element in nums2
  have the same parity.

  Therefore, we can always construct a uniform parity array.
*/

// T.C : O(1)
// S.C : O(1)
class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        return true;
    }
};
