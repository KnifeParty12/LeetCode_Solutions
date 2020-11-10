// https://leetcode.com/problems/strange-printer/submissions/

class Solution {
public:
    
    int solve(string str, int start, int end, vector<vector<int>> &dp){
        
        if(start > end) return 0;
        if(start == end) return 1;
        
        if(dp[start][end]!= -1) return dp[start][end];
        
        int res = INT_MAX;
        if(str[start] == str[start+1]) res = solve(str,start+1,end,dp);
        else if(str[end] == str[end-1] || str[start] == str[end])
            res = solve(str,start,end-1,dp);
        
        else{
        res = solve(str,start,end-1,dp) + 1; // last one completely different
        
            for(int k = start + 1; k < end; k++){
                if(str[k] == str[end])
                    res = min(res,solve(str,start,k-1,dp) + solve(str,k,end-1,dp)); 
        }
        }
        
        return dp[start][end] = res;
    }
    
    
    int strangePrinter(string str) {
         
        int n = str.length();
        if(n == 0) return 0;
        
        char prev = str[0]; // compression
        string res = "";
        res+=str[0];
        for(int i = 1; i<n; i++){
            if(str[i]!= prev){
                prev = str[i];
                res+=str[i];
            }
        }
        
        n = res.length();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        
        return solve(res,0,n-1,dp);
        
    }
};
