// GFG          : Unoccupied Computers
// Problem Link : https://www.geeksforgeeks.org/problems/unoccupied-computers-1646661078/1

// Approach (Simulation + Hash Table)
// T.C : O(|s|)
// S.C : O(1)
class Solution {
  public:
    int solve(int n, string s) {
        int mp[26];
        fill(begin(mp), end(mp), -1); // -1 -> have not arrive, 0 -> rejected, 1 -> assigned
        
        int occupied = 0;
        int result = 0;
        
        for(char ch : s) {
            if(mp[ch-'A'] == -1) { // arrival
                if(occupied < n) {
                    mp[ch-'A'] = 1;
                    occupied++;
                } else {
                    mp[ch-'A'] = 0;
                    result++;
                }
            } else { // departure
                if(mp[ch-'A'] == 1) occupied--;
            }
        }
        
        return result;
    }
};
