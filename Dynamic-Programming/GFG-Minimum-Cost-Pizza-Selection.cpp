// GFG          : Minimum Cost Pizza Selection
// Problem Link : https://www.geeksforgeeks.org/problems/pizza-mania0155/1

/*
  Intuition:
    At any point, we still need some remaining pizza area x.
    We have 3 choices:
      1. Buy a Small pizza.
      2. Buy a Medium pizza.
      3. Buy a Large pizza.

    This screams Recursion!!
    After choosing a pizza, reduce x by that pizza's area and recursively solve for the remaining required area.

    Since we only need the total area to be AT LEAST x, overshooting is valid.
    Therefore, once x <= 0, no additional cost is required.

  State:
    solve(x) = minimum cost required to obtain at least x more units of pizza area.

  Recurrence:
    solve(x) = 0, if x <= 0

    solve(x) = min({
                     smallCost  + solve(x - smallArea),
                      medCost    + solve(x - medArea),
                      largeCost  + solve(x - largeArea)
                  }), otherwise

  Answer:
    solve(x)
*/

// Approach 1 (Top-Down DP)
// T.C : O(x)
// S.C : O(x)
class Solution {
public:
    int smallArea, medArea, largeArea;
    int smallCost, medCost, largeCost;
    int dp[501];
    
    int solve(int x) {
        if(x <= 0)      return 0;
        if(dp[x] != -1) return dp[x];
        
        int takeSmall  = smallCost + solve(x-smallArea);
        int takeMedium = medCost   + solve(x-medArea);
        int takeLarge  = largeCost + solve(x-largeArea);
        
        return dp[x] = min({takeSmall, takeMedium, takeLarge});
    }
    
    int minimumCost(int x, int s, int m, int l, int cs, int cm, int cl) {
        smallArea = s,  medArea = m,   largeArea = l;
        smallCost = cs, medCost = cm,  largeCost = cl;
        
        memset(dp, -1, sizeof(dp));
        
        return solve(x);
    }
};

// Approach 2 (Bottom-Up DP)
// T.C : O(x)
// S.C : O(x)
class Solution {
public:
    int minimumCost(int x, int s, int m, int l, int cs, int cm, int cl) {
        // dp[i] = min. cost required to buy pizzas whose total area >= i
        vector<int> dp(x+1, 0);
        
        for(int i = 1; i <= x; i++) {
            int takeSmall = (i-s) >= 0 ? cs + dp[i-s] : cs;
            int takeMed   = (i-m) >= 0 ? cm + dp[i-m] : cm;
            int takeLarge = (i-l) >= 0 ? cl + dp[i-l] : cl;
            
            dp[i] = min({takeSmall, takeMed, takeLarge});
        }
        
        return dp[x];
    }
};
