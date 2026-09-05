// LeetCode 3904 : Smallest Stable Index II
// Problem Link  : https://leetcode.com/problems/smallest-stable-index-ii/

// Approach (Prefix-Suffix)
// T.C : O(n)
// S.C : O(n)
class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> suffixMin(n); // suffixMin[i] = min(nums[i...n-1])
        suffixMin[n-1] = nums[n-1];
        for(int i = n-2; i >= 0; i--) {
            suffixMin[i] = min(suffixMin[i+1], nums[i]);
        }

        int prefixMax = 0; // prefixMax = max(nums[0...i])
        for(int i = 0; i < n; i++) {
            prefixMax = max(prefixMax, nums[i]);

            if(prefixMax-suffixMin[i] <= k) return i;
        }

        return -1;
    }
};
