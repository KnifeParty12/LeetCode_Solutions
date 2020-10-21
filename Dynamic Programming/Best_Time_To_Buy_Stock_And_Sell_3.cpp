int memo[100005][3][2];

class Solution {
public:
    
    int solve(int *arr, int n, int k, int flag){
        if(n == 0) return 0;
        
        if(memo[n][k][flag] != -1) return memo[n][k][flag];
        
        if(flag){ // can either sell or ignore
            memo[n][k][flag] = max(solve(arr+1,n-1,k,flag), arr[0] + solve(arr+1,n-1,k-1,flag^1));
        }
        else{ // can buy or ignore
            if(k > 0) memo[n][k][flag] = max(solve(arr+1,n-1,k,flag),solve(arr+1,n-1,k,flag^1) - arr[0]);
            else memo[n][k][flag] = 0;
        }
        
        return memo[n][k][flag];
    }
    
    
    int maxProfit(vector<int>& price) {
        // memoized solution
        int n = price.size();
        if(n < 2) return 0;
        int arr[n];
        for(int i = 0; i<n; i++) arr[i] = price[i];
        
        for(int i = 0; i<=n; i++){
            for(int j = 0; j<3; j++){
                memo[i][j][0] = -1;
                memo[i][j][1] = -1;
            }
        }
        
        return solve(arr,n,2,0);
        
    }
};
