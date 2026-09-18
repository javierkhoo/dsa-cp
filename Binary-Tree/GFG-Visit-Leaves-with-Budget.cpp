// GFG          : Visit Leaves with Budget
// Problem Link : https://www.geeksforgeeks.org/problems/leaf-under-budget/1

/*
  A leaf’s cost is its level, and BFS visits nodes level by level.
  Therefore, BFS encounters leaf costs in non-decreasing order. (no explicit sort needed)
  To maximize the number of leaves visited within budget k, greedily take the cheapest leaves first.
*/

// Approach 1 (BFS + Store Leaf Costs + Greedy)
// T.C : O(n)
// S.C : O(n)
class Solution {
public: 
    void bfs(Node* root, vector<int>& leafCosts) {
        queue<Node*> que;
        que.push(root);
        
        int level = 1;
        
        while(!que.empty()) {
            int size = que.size();
            
            while(size--) {
                Node* node = que.front();
                que.pop();
                
                if(!node->left && !node->right) { // node is a leaf
                    leafCosts.push_back(level);
                }
                
                if(node->left) que.push(node->left);
                if(node->right) que.push(node->right);
            }
            
            level++;
        }
    }
    
    int getCount(Node *root, int k) {
        vector<int> leafCosts;
        bfs(root, leafCosts); // O(n)
        
        int result = 0;
        for(int cost : leafCosts) { // O(L), L <= n
            if(k-cost >= 0) {
                result++;
                k -= cost;
            } else break;
        }
        
        return result;
    }
};

// Approach 2 (BFS + Greedy On-the-Fly)
// T.C : O(n)
// S.C : O(n)
class Solution {
public:   
    int getCount(Node *root, int k) {
        queue<Node*> que;
        que.push(root);
        
        int result = 0;
        int level  = 1;
        
        while(!que.empty()) {
            int size = que.size();
            
            while(size--) {
                Node* node = que.front();
                que.pop();
                
                if(!node->left && !node->right) { // node is a leaf
                    if(k < level) return result;
                  
                    result++;
                    k -= level;
                }
                
                if(node->left) que.push(node->left);
                if(node->right) que.push(node->right);
            }
            
            level++;
        }
        
        return result;
    }
};
