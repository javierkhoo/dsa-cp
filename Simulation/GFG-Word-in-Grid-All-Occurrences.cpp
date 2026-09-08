// GFG          : Word in Grid - All Occurrences
// Problem Link : https://www.geeksforgeeks.org/problems/find-the-string-in-grid0111/1

// Approach (Simulation)
// T.C : O(mn|word|)
// S.C : O(1)
class Solution {
  public:
    using pii = pair<int, int>;
    
    int m;
    int n;
    
    bool traverse(int r, int c, int dr, int dc, vector<vector<char>>& mat, string& word) {
        int i = r, j = c;
        int k = 0;
        
        while(k < word.length()) { // O(|word|)
            if(i < 0 || i >= m || j < 0 || j >= n) return false;
            if(mat[i][j] != word[k]) return false;
            
            i += dr;
            j += dc;
            k++;
        }
        
        return true;
    }
    
    vector<vector<int>> searchWord(vector<vector<char>> &mat, string &word) {
        m = mat.size();
        n = mat[0].size();
        
        vector<pii> directions = {
            {-1,0}, {1,0}, {0,-1}, {0,1},  // Up, Down, Left, Right
            {-1,-1}, {1,1}, {-1,1}, {1,-1} // \, /
                                 };
        
        vector<vector<int>> result;
        
        for(int r = 0; r < m; r++) { // O(m)
            for(int c = 0; c < n; c++) { // O(n)
                for(auto& dir : directions) {
                    int dr = dir.first, dc = dir.second;
                    
                    if(traverse(r, c, dr, dc, mat, word)) { // O(|word|)
                        result.push_back({r, c});
                        break; // (r,c) is pushed into result at most once
                    }
                }
            }
        }
        
        return result;
    }
};
