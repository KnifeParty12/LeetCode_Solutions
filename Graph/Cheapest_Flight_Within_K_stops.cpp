#define pb push_back
#define MAX 105
#define pii pair<int,int>

class Solution {
public:
    
    vector<pii> adj[MAX];
    int dp[101][101];
    
    int solve(int i,int k, int dst){
        
        if(i == dst) return 0;
        
        if(k == 0) return INT_MAX;
        
        if(dp[i][k] != -1) return dp[i][k];
        
        int res = INT_MAX;
        
        for(pii it : adj[i]){ // calling neighbors
          //  cout<<it.first<<endl;
            int sm1 = solve(it.first,k-1,dst);
            if(sm1 != INT_MAX) res = min(res, it.second + sm1);
        }
        
        return dp[i][k] = res;
    }
    

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        for(int i = 0; i<n; i++) adj[i].clear();
        memset(dp, -1, sizeof dp);
        
        int m = flights.size(); // number of edges
        if(src == dst) return 0;
        
        for(int i = 0; i<m; i++){
            int f = flights[i][0];
            int s = flights[i][1];
            int w = flights[i][2];
            adj[f].pb({s,w}); // connection
        }
        
        // LOGIC
        // DP + DPS
        // dp[i][k] represents min cost to reach dst from i with k stops
        
        int ans = solve(src,k+1,dst);
        if(ans == INT_MAX) return -1;
        return ans;
    }
};
