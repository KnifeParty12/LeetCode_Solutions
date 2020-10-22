// https://leetcode.com/problems/longest-palindromic-subsequence/submissions/
class Solution {
public:
    
    int solve(string &str,int i, int j, vector<vector<int>> &memo){
        if(i == j) return 1;
        if(i > j ) return 0;
        
        if(memo[i][j] != -1) return memo[i][j];
        
        if(str[i] == str[j]) memo[i][j] = 2 + solve(str,i+1,j-1,memo);
        else memo[i][j] = max(solve(str,i+1,j,memo),solve(str,i,j-1,memo));
        return memo[i][j];
    }
    
    
    int longestPalindromeSubseq(string s) {
        
        int n = s.length();
        if(n == 0) return 0;
        vector<vector<int>> memo(n,vector<int>(n,-1));

        return solve(s,0,n-1,memo);
    }
};
