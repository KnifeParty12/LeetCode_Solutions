int dp[50005][2];

int sz;

class Solution {
public:
    
    int solve(vector<int> &arr, int n, int fee,int flag){
        if(n == 0) return 0;
        
        if(dp[n][flag] != -1) return dp[n][flag];
        
        if(flag){ //sell or ignore
            dp[n][flag] = max(solve(arr,n-1,fee,flag),solve(arr,n-1,fee,flag^1) + arr[sz - n] - fee);
        }
        else{
            dp[n][flag] = max(solve(arr,n-1,fee,flag),solve(arr,n-1,fee,flag^1) - arr[sz - n]);      
        }
        return dp[n][flag];
    }
    
    
    int maxProfit(vector<int>& price, int fee) {
        
        int n = price.size();
        if(n < 2) return 0;
        
        sz = n;
        for(int i = 0; i<=n; i++){
            dp[i][0] = -1;
            dp[i][1] = -1;
        }
        
        return solve(price,n,fee,0);
    }
};
