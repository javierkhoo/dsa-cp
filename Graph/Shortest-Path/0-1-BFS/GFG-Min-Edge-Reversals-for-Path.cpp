// GFG          : Min Edge Reversals for Path
// Problem Link : https://www.geeksforgeeks.org/problems/minimum-edges/1

/*
  Treat each original edge u -> v as cost 0, since no reversal is needed.
  Add the reverse edge v -> u with cost 1, representing one reversal.

  The problem then becomes:
    Find the Shortest 0/1-Weighted Path from SRC to DST.
  => 0-1 BFS!!
*/

// Approach (0-1 BFS)
// T.C : O(n + m), m = no. of edges
// S.C : O(n + m)
class Solution {
public: 
    using pii = pair<int, int>;
    
    int minimumEdgeReversal(vector<vector<int>> &edges, int n, int src, int dst) {
        vector<vector<pii>> adj(n+1);
        
        for(vector<int>& e : edges) {
            int u = e[0];
            int v = e[1];
            
            adj[u].push_back({v, 0});
            adj[v].push_back({u, 1});
        }
        
        // dist[i] = min sum of edge weights of src->i
        //         = min reversals needed to reach i from src
        vector<int> dist(n+1, INT_MAX);
        deque<int> dq;
        
        dist[src] = 0;
        dq.push_back(src);
        
        while(!dq.empty()) {
            int u = dq.front();
            dq.pop_front();
            
            for(auto& [v,w] : adj[u]) {
                if(dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    
                    if(w == 0) {
                        dq.push_front(v);
                    } else {
                        dq.push_back(v);
                    }
                }
            }
        }
        
        return (dist[dst] == INT_MAX) ? -1 : dist[dst];
    }
};
