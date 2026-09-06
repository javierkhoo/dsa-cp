// GFG          : Sum of Pairwise ANDs
// Problem Link : https://www.geeksforgeeks.org/problems/sum-of-products5049/1

// Approach 1 (Brute-Force / Simulation)
// T.C : O(n^2) (TLE)
// S.C : O(1)
class Solution {
  public:
    long long pairAndSum(vector<int> &arr) {
        int n = arr.size();
        
        long long result = 0;
        
        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                result += (arr[i] & arr[j]);
            }
        }
        
        return result;
    }
};

// Approach 2 (Bit Contribution)
// T.C : O(32n) = O(n)
// S.C : O(1)
class Solution {
  public:
    using ll = long long;
    
    long long pairAndSum(vector<int> &arr) {
        int n = arr.size();
        
        ll result = 0;
        
        for(int bitPos = 0; bitPos <= 31; bitPos++) {
            ll countOfSetBits = 0;
            
            for(int x : arr) {
                if(x & (1LL << bitPos)) { // bitPos in x is set
                  countOfSetBits++;
                }
            }
            
            ll pairs = (countOfSetBits * (countOfSetBits-1)) / 2; 
            result += (pairs * (1LL << bitPos)); // each pair contributes 2^bitPos to result
        }
        
        return result;
    }
};
