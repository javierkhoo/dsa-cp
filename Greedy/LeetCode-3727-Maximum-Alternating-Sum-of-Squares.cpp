// LeetCode 3727 : Maximum Alternating Sum of Squares
// Problem Link  : https://leetcode.com/problems/maximum-alternating-sum-of-squares/

// Intuition (Greedy + Sorting):
//     - Even indices contribute positively, while odd indices contribute negatively.
//     - To maximize the alternating sum, assign the smallest floor(n/2) squared values to odd indices
//       and the remaining ceiling(n/2) largest values to even indices.
//
// Correctness Proof (Exchange Argument):
//     - Suppose x <= y, where x occupies a positive position and y a negative position.
//     - Their current contribution is x - y.
//     - Swapping them changes their contribution to y - x.
//     - The difference is (y - x) - (x - y) = 2(y - x) >= 0.
//     - Therefore, such a swap never decreases the alternating sum.
//     - Repeatedly applying these exchanges yields an optimal arrangement where
//       the smallest squared values occupy negative positions and the largest
//       squared values occupy positive positions.

// Approach 1 (Ordered Map + Greedy)
// T.C : O(nlogn)
// S.C : O(n)
class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        // All odd indices greedily put small numbers starting from 0
        
        int n = nums.size();

        map<int, int> mp;
        for(int num : nums) {
            mp[abs(num)]++; // mp[0] will always be at the top
        }

        long long result = 0;
        for(int i = 1; i < n; i += 2) {
            int key  = mp.begin()->first;
            int freq = mp.begin()->second;
            
            if(freq > 0) {
                result -= key*key;
                mp[key]--;
            } else {
                mp.erase(key);
                int newKey = mp.begin()->first;
                result -= newKey*newKey;
                mp[newKey]--;
            }
        }

        for(int i = 0; i < n; i += 2) {
            int key  = mp.begin()->first;
            int freq = mp.begin()->second;

            if(freq > 0) {
                result += key*key;
                mp[key]--;
            } else {
                mp.erase(key);
                int newKey = mp.begin()->first;
                result += newKey*newKey;
                mp[newKey]--;
            }
        }

        return result;
    }
};

// Approach 2 (Sorting + Greedy)
// T.C : O(nlogn)
// S.C : O(n)
class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();

        vector<int> squares(n, 0);
        for(int i = 0; i < n; i++) {
            squares[i] = nums[i] * nums[i];
        }

        sort(squares.begin(), squares.end());

        long long result = 0;

        // First Half of squares go to odd indices
        for(int i = 0; i < n/2; i++) {
            result -= squares[i];
        }

        // Second Half of squares go to even indices
        for(int i = n/2; i < n; i++) {
            result += squares[i];
        }

        return result;
    }
};

// Approach 3 (In-place Sorting + Greedy)
// T.C : O(nlogn)
// S.C : O(logn) (std::sort stack)
class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin(), nums.end(), [](int a, int b) {
            return abs(a) < abs(b);
        });

        long long result = 0;

        // First Half of nums go to odd indices
        for(int i = 0; i < n/2; i++) {
            result -= nums[i]*nums[i];
        }

        // Second Half of nums go to even indices
        for(int i = n/2; i < n; i++) {
            result += nums[i]*nums[i];
        }

        return result;
    }
};

// Approach 4 (In-place Squaring + Sorting + Greedy)
// T.C : O(nlogn)
// S.C : O(logn) (std::sort stack)
class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();

        for(int i = 0; i < n; i++) {
            nums[i] *= nums[i];
        }

        sort(nums.begin(), nums.end());

        long long result = 0;

        // First Half of nums go to odd indices
        for(int i = 0; i < n/2; i++) {
            result -= nums[i];
        }

        // Second Half of nums go to even indices
        for(int i = n/2; i < n; i++) {
            result += nums[i];
        }

        return result;
    }
};
