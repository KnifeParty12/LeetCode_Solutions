// https://leetcode.com/problems/unique-paths/
class Solution {
public:
    int uniquePaths(int m, int n) {
        
        int dp[m][n];
        dp[m-1][n-1] = 1; // already at end point
        
        //last row
        for(int i = n-2; i>=0; i--) dp[m-1][i] = 1;
        //last column
        for(int i = m-2; i>=0; i--) dp[i][n-1] = 1;
        
        for(int i = m-2; i>=0; i--){
            for(int j = n-2; j>=0; j--) dp[i][j] = dp[i+1][j] + dp[i][j+1];
        }
        return dp[0][0];
    }
};
