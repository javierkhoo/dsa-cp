// GFG          : Bird and Max Fruit Gathering
// Problem Link : https://www.geeksforgeeks.org/problems/bird-and-maximum-fruit-gathering--170645/1

// Approach 1 (Brute Force + Sliding Window) - TLE
// T.C : O(n + m^2) = O(n^2), since m <= n
// S.C : O(1)
class Solution {
  public:
    int maxFruits(vector<int>& arr, int m) {
        int n = arr.size();

        m = min(m, n); // safety guard
        
        int result = INT_MIN;
        
        int i = 0;
        int j = 0;
        int fruits = 0;
        while(j < n) { // non-wrapping window
            fruits += arr[j];
            
            while(j - i + 1 > m) {
                fruits -= arr[i];
                i++;
            }
            
            result = max(result, fruits); // For all k, arr[k] >= 0, so safe to update here
            j++;
        }

        // wrapping window
        for(int takeFromEnd = 1; takeFromEnd <= m-1; takeFromEnd++) { // O(m)
            int fruits = 0;
            
            for(int i = n-takeFromEnd; i < n; i++) { // O(takeFromEnd)
                fruits += arr[i];
            }
            
            for(int k = 0; k < m-takeFromEnd; k++) { // O(m-takeFromEnd)
                fruits += arr[k];
            }
            
            result = max(result, fruits);
        }
        
        return result;
    }
};

// Approach 2 (Two-Phase Sliding Window)
// T.C : O(n + m) = O(n), since m <= n
// S.C : O(1)
class Solution {
  public:
    int maxFruits(vector<int>& arr, int m) {
        int n = arr.size();
        
        m = min(m, n); // safety guard
        
        int result = INT_MIN;
        
        int i = 0;
        int j = 0;
        int fruits = 0;
        while(j < n) { // non-wrapping window
            fruits += arr[j];
            
            while(j - i + 1 > m) {
                fruits -= arr[i];
                i++;
            }
            
            result = max(result, fruits); 
            j++;
        }
        
        i++;
        j = 0;
        while(j < m-1) { // wrapping window
            fruits -= arr[i-1];
            fruits += arr[j];
            
            i++;
            j++;
            
            result = max(result, fruits);
        }
        
        return result;
    }
};

// Approach 3 (Sliding Window + Extended Array)
// T.C : O(n+m) = O(n), since m <= n
// S.C : O(n+m) = O(n), since m <= n
class Solution {
  public:
    int maxFruits(vector<int>& arr, int m) {
        int n = arr.size();
        
        m = min(m, n); // safety guard
        
        vector<int> nums = arr;
        for(int i = 0; i < m-1; i++) {
            nums.push_back(arr[i]);
        }
        
        int result = INT_MIN;
        
        int i = 0;
        int j = 0;
        int fruits = 0;
        while(j < nums.size()) { 
            fruits += nums[j];
            
            while(j - i + 1 > m) {
                fruits -= nums[i];
                i++;
            }
            
            result = max(result, fruits); // For all k, arr[k] >= 0, so safe to update here
            j++;
        }
        
        return result;
    }
};

// Approach 4 (Circular Sliding Window; motivated by Approach 3)
// T.C : O(n+m) = O(n), since m <= n
// S.C : O(1)
class Solution {
  public:
    int maxFruits(vector<int>& arr, int m) {
        int n = arr.size();
        
        m = min(m, n); // safety guard
        
        int result = INT_MIN;
        
        int i = 0;
        int j = 0;
        int fruits = 0;
        while(j < n+m-1) { 
            fruits += arr[j % n];
            
            while(j - i + 1 > m) {
                fruits -= arr[i % n];
                i++;
            }
            
            result = max(result, fruits); // For all k, arr[k] >= 0, so safe to update here
            j++;
        }
        
        return result;
    }
};
