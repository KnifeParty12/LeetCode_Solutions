// DP + Backtracking

class Solution {
public:
    
    int m,n;    
    int solve(vector<vector<int>> &arr, int x, int y,
              vector<vector<int>> &dp,vector<vector<bool>> &visited){
        
        if(x == m-1  && y == n-1) return 1;
        if(x < 0 || x == m || y < 0 || y == n) return 0;
        if(arr[x][y]) return 0; // obstacle
        if(visited[x][y]) return 0;
        
        if(dp[x][y] != -1) return dp[x][y];
        
        visited[x][y] = true;
        int res = 0;
        res += solve(arr,x+1,y,dp,visited) + solve(arr,x,y+1,dp,visited);
        visited[x][y] = false; // backtrack
        dp[x][y] = res;
        return res;
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& arr) {
        
         m = arr.size();
        if(!m) return 0;
         n = arr[0].size();
        if(!n) return 0;
        if(arr[0][0] == 1 || arr[m-1][n-1] == 1) return 0;
        
        vector<vector<int>> dp(m,vector<int>(n,-1));
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        int ans = solve(arr,0,0,dp,visited);
     //   cout<<dp[m-1][n-2]<<endl;
        return ans;
    }
};
