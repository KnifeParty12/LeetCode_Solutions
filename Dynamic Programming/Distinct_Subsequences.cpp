// https://leetcode.com/problems/distinct-subsequences/submissions/

int m,n;

class Solution {
public:
    
    int solve(string &s, string &t, int i, int j,vector<vector<int>> &memo){
        
        if(j == 0) return 1;
        if(i == 0) return 0;
        
        if(memo[i][j]!= -1) return memo[i][j];
        
        if(s[m - i] == t[n - j]) memo[i][j] =  solve(s,t,i-1,j-1,memo) + solve(s,t,i-1,j,memo);
        else memo[i][j] = solve(s,t,i-1,j,memo);
        return memo[i][j];
    }
    
    
    int numDistinct(string s, string t) {
     
         m = s.length();
         n = t.length();
        
        if(n > m) return 0;
        
        vector<vector<int>> memo(m+1,vector<int>(n+1,-1));
        
        return solve(s,t,m,n,memo);
        
    }
};
