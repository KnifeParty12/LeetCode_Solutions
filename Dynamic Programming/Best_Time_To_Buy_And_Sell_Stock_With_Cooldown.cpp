int sz;
class Solution {
public:
    
    int solve(vector<int> &arr, int n, int flag, vector<vector<int>> &memo){
        if(n <= 0) return 0;
        
        if(memo[n][flag] != -1) return memo[n][flag];
        
        if(flag){ // sell or ignore
            memo[n][flag] = max(solve(arr,n-1,flag,memo),solve(arr,n-2,flag^1,memo) + arr[sz-n]);
        }
        else{
            memo[n][flag] = max(solve(arr,n-1,flag,memo),solve(arr,n-1,flag^1,memo) - arr[sz-n]);
        }
        return memo[n][flag];
    }
    
    
    int maxProfit(vector<int>& price) {
        int n = price.size();
        if(n < 2) return 0;
        
        vector<vector<int>>memo(n+1,vector<int>(2,-1));
        sz = n;
        
        return solve(price,n,0,memo);
        
    }
};
