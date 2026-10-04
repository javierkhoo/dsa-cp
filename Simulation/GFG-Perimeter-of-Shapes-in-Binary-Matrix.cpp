// GFG          : Perimeter of Shapes in Binary Matrix
// Problem Link : https://www.geeksforgeeks.org/problems/find-perimeter-of-shapes/1

// Approach 1 (Simulation)
// T.C : O(mn)
// S.C : O(1)
class Solution {
public:
    int findPerimeter(vector<vector<int>> &mat) {
        int m = mat.size();
        int n = mat[0].size();
        
        int result = 0;

        // Count every exposed side of each 1-cell.
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(mat[i][j] == 0) continue;
                
                // Check Left Neighbour
                if(j-1 < 0 || mat[i][j-1] == 0) result++;
                
                // Check Up Neighbour
                if(i-1 < 0 || mat[i-1][j] == 0) result++;
                
                // Check Right Neighbour
                if(j+1 >= n || mat[i][j+1] == 0) result++;
                
                // Check Down Neighbour
                if(i+1 >= m || mat[i+1][j] == 0) result++;
            }
        }
        
        return result;
    }
};

// Approach 2 (Mathematical Observation)
// T.C : O(mn)
// S.C : O(1)
class Solution {
public:
    int findPerimeter(vector<vector<int>> &mat) {
        int m = mat.size();
        int n = mat[0].size();
        
        int result = 0;
      
        // Every 1-cell contributes 4 sides initially.
        // Each shared edge between two adjacent 1-cells is counted twice, so subtract 2 for each shared edge.
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(mat[i][j] == 0) continue;
                
                result += 4;
                
                // Check Up Neighbour (if any)
                if(i-1 >= 0 && mat[i-1][j] == 1) result -= 2;
                
                // Check Left Neighbour (if any)
                if(j-1 >= 0 && mat[i][j-1] == 1) result -= 2;
            }
        }
        
        return result;
    }
};
