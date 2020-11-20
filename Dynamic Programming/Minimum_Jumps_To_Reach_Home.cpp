// https://leetcode.com/problems/minimum-jumps-to-reach-home/submissions/

#define pb push_back
#define MAX 6000

class Solution {
public:
    int dp[6005][2];
    
    int solve(int curr, unordered_set<int> &no, int a, int b, int x,int bj){
        
        if(curr == x) return 0;
        
        if(curr > MAX || curr < 0 || no.find(curr) != no.end()) return 1e7;
    
        if(dp[curr][bj] != -1) return dp[curr][bj];
        
        int f = curr + a;
        int bc = curr - b;
        
        dp[curr][bj] = 1 + solve(f,no,a,b,x,0);
        
        if(bj != 1)
            dp[curr][bj] = min(dp[curr][bj],1 + solve(bc,no,a,b,x,1));
        
        return dp[curr][bj];
    }
    
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {

        int n = forbidden.size();
        unordered_set<int> no;
        if(x == 0) return 0;
        for(int i = 0; i<n; i++) no.insert(forbidden[i]);
        memset(dp,-1,sizeof dp);

        int res = solve(0,no,a,b,x,0);
        if(res >= 1e7) return -1;
        return res;
        
    }
};
