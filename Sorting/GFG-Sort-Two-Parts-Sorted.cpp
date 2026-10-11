// GFG          : Sort Two Parts Sorted
// Problem Link : https://www.geeksforgeeks.org/problems/sort-the-half-sorted2157/1

// Approach (Sorting + Two Pointers)
// T.C : O(n)
// S.C : O(n)
// Intuition:
//     Find the first index where the nondecreasing order is violated, separating the array into two sorted portions.
//     Merge both portions using two pointers, repeatedly selecting the smallest remaining element greedily.
class Solution {
public:
    void mergeTwoParts(vector<int>& arr) {
        int n = arr.size();
        
        int pivotIdx = 0;
        for(int i = 1; i < n; i++) {
            if(arr[i] < arr[i-1]) {
                pivotIdx = i;
                break;
            }
        }
        
        if(pivotIdx == 0) return; // early return (handles already sorted array, empty array, singleton array)
        
        vector<int> firstPart;
        for(int i = 0; i < pivotIdx; i++) {
          firstPart.push_back(arr[i]);
        }
        
        vector<int> secondPart;
        for(int i = pivotIdx; i < n; i++) {
          secondPart.push_back(arr[i]);
        }

        int i = 0, j = 0, k = 0;
        while(i < firstPart.size() && j < secondPart.size()) {
            if(firstPart[i] <= secondPart[j]) { // <= for stability
                arr[k++] = firstPart[i++];
            } else {
                arr[k++] = secondPart[j++];
            }
        }
        
        while(i < firstPart.size()) arr[k++] = firstPart[i++];
        while(j < secondPart.size()) arr[k++] = secondPart[j++];
    }
};
