// GFG          : Adding Ones
// Problem Link : https://www.geeksforgeeks.org/problems/adding-ones3628/1

// Approach 1 (Brute-Force)
// T.C : O(nk) (TLE)
// S.C : O(1)
class Solution {
public:
    vector<int> update(int n, vector<int>& updates) {
        vector<int> arr(n, 0);
        
        for(int j : updates) {
            for(int i = j-1; i < n; i++) {
                arr[i]++;
            }
        }
        
        return arr;
    }
};

// Approach 2 (Difference Array Technique)
// Intuition (Difference Array + Prefix Sum):
//     - Brute Force repeatedly scans through every index i >= j for each update j in updates[].
//     - Instead, we can use a difference array to record where each increment starts and ends.
//     - After processing all updates in O(1) time each, we compute prefix sums on diff[] to propagate their contributions and hence reconstruct the final array.
// T.C : O(n + k)
// S.C : O(n)
class Solution {
public:
    vector<int> update(int n, vector<int>& updates) {
        vector<int> arr(n, 0);
        vector<int> diff(n+1, 0);
        
        for(int j : updates) {
            int l = j-1;
            int r = n-1;
            
            diff[l]++;
            diff[r+1]--;
        }
        
        arr[0] = diff[0];
        for(int i = 1; i < n; i++) {
            arr[i] = arr[i-1] + diff[i];
        }
        
        return arr;
    }
};
