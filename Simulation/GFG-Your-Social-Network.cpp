// GFG          : Your Social Network
// Problem Link : https://www.geeksforgeeks.org/problems/your-social-network0328/1

// Approach (Simulation)
// T.C : O(n^2)
// S.C : O(n)
class Solution {
public:
    vector<vector<int>> socialNetwork(vector<int>& arr) {
        int n = arr.size() + 1;
        
        vector<vector<int>> result;
        
        for(int i = 2; i <= n; i++) { // O(n)
            vector<vector<int>> temp;
            
            int j = i;
            int k = 1;
            while(arr[j-2] != 1) { // O(n)
                temp.push_back({i, arr[j-2], k});
                j = arr[j-2];
                k++;
            }
            
            temp.push_back({i, 1, k});
            reverse(temp.begin(), temp.end()); // O(n)
            
            for(vector<int>& vec : temp) { // O(n)
                result.push_back(vec);
            }
        }
        
        return result;
    }
};
