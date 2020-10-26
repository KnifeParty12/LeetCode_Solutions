// https://leetcode.com/problems/minimum-cost-to-merge-stones/

class Solution {
public:
    
    int dp[31][31];
    int prefix[31];
    int n;
    
    int solve(vector<int> &stones, int start, int end, int k){

        // BASE CASE
        int len = end - start + 1;
        if(len < k) return 0;

        if(dp[start][end]!= -1) return dp[start][end];
        
        int res = 1e5;
        for(int i = start; i<end; i+=k-1){ // need to make (k-1) size gaps so that we don't make useless calls
            res = min(res,solve(stones,start,i,k) + solve(stones,i+1,end,k));
        }
        if((len - k)%(k-1) == 0){
            res += prefix[end];
            if(start != 0) res -= prefix[start-1];
        }
        dp[start][end] = res;
        return dp[start][end];
    }
    
    
    int mergeStones(vector<int>& stones, int k) {
        
        n = stones.size();
        if((n-k)%(k-1) != 0) return -1;
        
        memset(dp,-1,sizeof dp);
        memset(prefix,0,sizeof prefix);
        
        prefix[0] = stones[0];
        for(int i = 1; i<n; i++) prefix[i] = prefix[i-1] + stones[i];
        
        return solve(stones,0,n-1,k);
    }
};
