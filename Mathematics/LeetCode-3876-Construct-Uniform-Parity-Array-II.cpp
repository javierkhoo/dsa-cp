// LeetCode 3876 : Construct Uniform Parity Array II
// Problem Link  : https://leetcode.com/problems/construct-uniform-parity-array-ii/

// Approach (Mathematical Observation)

/*
  Key Observation:
  ----------------
  For nums2[i] = nums1[i] - nums1[j] to be valid, we need nums1[i] - nums1[j] >= 1 <=> nums1[i] > nums1[j].
  
  Therefore, nums1[i] can only be modified by subtracting a STRICTLY smaller element from nums1.

  In particular, the minimum element can never be modified, so it must remain unchanged in nums2.

  Therefore, the parity needs to follow that of the minimum element in nums1.
  Let mn = min(nums1).

  Case 1: mn is odd.
  --------------------------------
  Then, for every x in nums1:
    - If x is odd, we take it directly.
    - Otherwise, x is even. Since there is at least one odd element (mn),
      we can subtract mn from x, and x > mn and even - odd = odd.

  Case 2: mn is even.
  ---------------------------------------
  Then, for every x in nums1:
    - If x is even, we take it directly.
    - Otherwise, x is odd. To make x even, we need to subtract it by an odd number y s.t. x > y.
    - To increase the chances that x > y, we assume that y is the minimum odd number in nums1.
    - But when it is y turn to become even, there can never be another odd number in nums1 that is smaller than y.
    - So, y cannot become even.

  Conclusion (Story to Code):
  -----------
  - mn is odd  -> true.
  - mn is even -> true iff every other element is even.
*/

// T.C : O(n)
// S.C : O(1)
class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int mn = *min_element(nums1.begin(), nums1.end());

        if(abs(mn) & 1) return true;

        for(int x : nums1) {
            if(abs(x) & 1) return false;
        }

        return true;
    }
};
