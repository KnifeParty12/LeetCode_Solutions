// https://leetcode.com/problems/wildcard-matching/submissions/

class Solution {
public:
    
    int solve(string &str, string &pat, int i, int j,vector<vector<int>> &dp){
        
        if(i == 0){
            if(j == 0) return 1;
            else if(j > 0 && pat[j-1] == '*') return solve(str,pat,i,j-1,dp);
            else return 0;
        }
        if(j <=0) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        if(str[i-1] == pat[j-1] || pat[j-1] == '?') dp[i][j] = solve(str,pat,i-1,j-1,dp);
        else if(pat[j-1] == '*') dp[i][j] = solve(str,pat,i-1,j,dp) || 
            solve(str,pat,i,j-1,dp);
        else dp[i][j] = 0;
        
        return dp[i][j];
    }
    
        
    bool isMatch(string s, string p) {
            
        int sz = s.length();
        int pz = p.length();
        if(sz == 0 && pz == 0) return true;
        // 1st optimization :: compress p if containing "****" subsegments
        //coz "*****" == "*"
        string pat = "";
        pat+=p[0];
        for(int i = 1; i<pz; i++){
            if(p[i] != p[i-1]) pat+=p[i];
            else if(p[i] != '*' ) pat+=p[i];
        }
        pz = pat.length();
        vector<vector<int>> dp(sz+1,vector<int>(pz+1,-1));
        
        return solve(s,pat,sz,pz,dp);
        
    }
    
};  
