// GFG          : Max Path Sum Between Two Leaves
// Problem Link : https://www.geeksforgeeks.org/problems/maximum-path-sum/1

/*
  Let dfs(node) = maximum node->leaf path sum.

  Recurrence:
    Leaf:
      dfs(node) = node->data
    
    Only One Child (Left Child):
      dfs(node) = node->data + dfs(node->left)
    
    Only One Child (Right Child):
      dfs(node) = node->data + dfs(node->right)
    
    Two Children:
      dfs(node) = node->data + max(dfs(node->left), dfs(node->right))
      
      ∃ leaf->leaf path P passing through node (LCA) with sum:
        dfs(node->left) + node->data + dfs(node->right)
*/

// Approach (Tree DP / Postorder DFS)
// T.C : O(n)
// S.C : O(logn), O(n) worst-case
class Solution {
public:
    int result;
    
    int dfs(Node* node) {
        // Leaf
        if(!node->left && !node->right) return node->data;
        
        // Only Right Child
        if(!node->left) return node->data + dfs(node->right);
        
        // Only Left Child
        if(!node->right) return node->data + dfs(node->left);
        
        int leftSum  = dfs(node->left);
        int rightSum = dfs(node->right); 
        
        result = max(result, node->data + leftSum + rightSum);
        
        return node->data + max(leftSum, rightSum);
    }
    
    int maxPathSum(Node* root) {
        if(!root) return -1;
        
        result = INT_MIN;
        dfs(root);
        return (result == INT_MIN) ? -1 : result;
    }
};
