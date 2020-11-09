// https://leetcode.com/problems/knight-dialer/submissions/

#define mod 1000000007
typedef long long ll;

class Solution {
public:
    
    vector<vector<int>> dir = {{4,6,-1}, {6,8,-1},{7,9,-1},{4,8,-1},{3,0,9},
                               {-1,-1,-1},{0,7,1},{6,2,-1},{1,3,-1},{2,4,-1}}; 
    
    ll solve(int start, int n, vector<vector<int>> &dp){
        
        if(start == -1) return 0;
        if(n == 1) return 1;

        if(dp[start][n] != -1) return dp[start][n];
        
        ll res = 0;
        for(int i = 0; i<dir[start].size(); i++) 
            res = (res + solve(dir[start][i],n-1,dp)) %mod;
        
        return dp[start][n] = res;
        }
        
    int knightDialer(int n) {
     
        // LOGIC
        // result depends on n and where we start from except * and #
        ll ans = 0;
        for(int i = 0; i< 10; i++){
            vector<vector<int>> dp(10,vector<int>(n+1,-1));
            ans += solve(i,n,dp);
            ans %= mod;
        }
        
        return ans;
    }
};
