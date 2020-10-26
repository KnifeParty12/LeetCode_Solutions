class Solution {
public:
    
    bool canPartition(vector<int>& arr) {
        
        int n = arr.size();
        //LOGIC
        // need to use all elements in the 2 subsets
        int sum = 0;
        for(int i = 0; i<n; i++) sum+=arr[i];
        
        if(sum&1) return false; // odd sum ain't possible
        
        sum/=2;
        bool dp[2][sum+1];
        
        for(int i = 0; i<=sum; i++) dp[1][i] = 0, dp[0][i] = 0;
        
        
        dp[1][0] = 1;
        dp[0][0] = 1;
        // odd index at 1 // even at 0
        for(int i = 0; i<n; i++){
            for(int j = 1; j<=sum; j++){
            if(i&1){
                dp[1][j] = dp[0][j];
                if(arr[i] <= j) dp[1][j] |= dp[0][j - arr[i]];
            }
            else{
                dp[0][j] = dp[1][j];
                if(arr[i] <= j) dp[0][j] |= dp[1][j - arr[i]]; 
            }
            }
        }
        
        return (n&1) ? dp[0][sum] : dp[1][sum];
        
    }
};
