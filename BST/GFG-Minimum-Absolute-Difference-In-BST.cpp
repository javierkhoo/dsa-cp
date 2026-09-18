// GFG          : Minimum Absolute Difference In BST
// Problem Link : https://www.geeksforgeeks.org/problems/minimum-absolute-difference-in-bst-1665139652/1

/*
  Suppose a < b < c.
  Then:
    c - a = (b - a) + (c - b)

  Since both (b - a) and (c - b) are positive:
    c - a > b - a
    c - a > c - b

  Therefore, two non-adjacent values cannot have the minimum difference.
  Hence, in sorted order, the minimum difference must occur between two adjacent values.
*/

// Approach 1 (Inorder Traversal + Store Sorted Values)
// T.C : O(n)
// S.C : O(n)
class Solution {
public:
    vector<int> inOrder;
    
    void inOrderDFS(Node* root) {
        if(!root) return;
        
        inOrderDFS(root->left);
        inOrder.push_back(root->data);
        inOrderDFS(root->right);
    }
    
    int absDiff(Node *root) {
        inOrder.clear();
        inOrderDFS(root);
        
        int result = INT_MAX;
        for(int i = 1; i < inOrder.size(); i++) {
            result = min(result, inOrder[i]-inOrder[i-1]);
        }
        
        return result;
    }
};

// Approach 2 (Inorder Traversal + Track Previous Node)
// T.C : O(n)
// S.C : O(h)
class Solution {
public:
    int result;
    Node* prev;
    
    void inOrderDFS(Node* root) {
        if(!root) return;
        
        inOrderDFS(root->left);
        
        if(prev) {
            result = min(result, root->data - prev->data);
        }
        
        prev = root;
        
        inOrderDFS(root->right);
    }
    
    int absDiff(Node *root) {
        result = INT_MAX;
        prev   = nullptr;
        
        inOrderDFS(root);
        
        return result;
    }
};
