// https://leetcode.com/problems/tallest-billboard/submissions/

int dp[21][10001];

class Solution {
public:
    
    int solve(vector<int> &rods,int n,int ls){
        if(n == 0){
            if(ls == 0) return 0;
            else return -10000;
        }
        if(dp[n][5000 + ls] != -1) return dp[n][5000+ls];
        
        dp[n][5000 + ls] = max({solve(rods,n-1,ls),
                                rods[n-1] + solve(rods,n-1,ls + rods[n-1]),
                                 solve(rods,n-1,ls-rods[n-1])});
        return dp[n][5000+ls];   
    }
    
    
    int tallestBillboard(vector<int>& rods) {
        
        int n = rods.size();
        if(n == 0) return 0;
        
        int sum = 0;
        for(int i = 0; i<n; i++)sum+=rods[i];
        memset(dp,-1,sizeof dp);
        return solve(rods,n,0);
    }
};
