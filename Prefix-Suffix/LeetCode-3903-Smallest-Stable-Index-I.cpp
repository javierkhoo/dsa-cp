// LeetCode 3903 : Smallest Stable Index I
// Problem Link  : https://leetcode.com/problems/smallest-stable-index-i/

// Approach 1 (Brute Force / Simulation)
// T.C : O(n^2)
// S.C : O(1)
class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();

        for(int i = 0; i < n; i++) {
            int mx = *max_element(nums.begin(), nums.begin() + i + 1);
            int mn = *min_element(nums.begin() + i, nums.end());

            if(mx-mn <= k) return i;
        }

        return -1;
    }
};

// Approach 2 (Prefix-Max and Suffix-Min Precomputation)
// T.C : O(n)
// S.C : O(n)
class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> prefixMax(n); // prefixMax(i) = max(nums[0...i])
        prefixMax[0] = nums[0];
        for(int i = 1; i < n; i++) {
            prefixMax[i] = max(prefixMax[i-1], nums[i]);
        }

        vector<int> suffixMin(n); // sufffixMin(i) = min(nums[i...n-1])
        suffixMin[n-1] = nums[n-1];
        for(int i = n-2; i >= 0; i--) {
            suffixMin[i] = min(suffixMin[i+1], nums[i]);
        }

        for(int i = 0; i < n; i++) {
            int mx = prefixMax[i];
            int mn = suffixMin[i];

            if(mx-mn <= k) return i;
        }

        return -1;
    }
};

// Approach 3 (Same as Approach 2, but calculate prefixMax on the fly)
// T.C : O(n)
// S.C : O(n) + O(1) = O(n)
class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> suffixMin(n); // suffixMin(i) = min(nums[i...n-1])
        suffixMin[n-1] = nums[n-1];
        for(int i = n-2; i >= 0; i--) {
            suffixMin[i] = min(suffixMin[i+1], nums[i]);
        }

        int prefixMax = nums[0];
        for(int i = 0; i < n; i++) {
            prefixMax = max(prefixMax, nums[i]); // same as recurrence prefixMax[i] = max(nums[i], prefixMax[i-1]), only prefixMax[i-1] is needed

            int mx = prefixMax;
            int mn = suffixMin[i];

            if(mx-mn <= k) return i;
        }

        return -1;
    }
};
