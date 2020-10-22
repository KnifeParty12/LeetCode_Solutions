//https://leetcode.com/problems/knight-probability-in-chessboard/submissions/


vector<pair<int,int>> dir = {{-1,-2},{-2,-1},{1,-2},{2,-1},{-2,1},{-1,2},{1,2},{2,1}};

class Solution {
public:
    double solve(int n,int k, int x, int y,vector<vector<vector<double>>> &memo){
        if(x < 0 || x >= n || y < 0 || y>=n) return 0;
        if(k == 0) return 1;
        
        if(memo[x][y][k] != 0) return memo[x][y][k];
        
        for(int i = 0; i<8; i++){ // 8 possible moves
            int nx = x + dir[i].first;
            int ny = y + dir[i].second;
            memo[x][y][k] += solve(n,k-1,nx,ny,memo);
        }
        memo[x][y][k]/=8;
        return memo[x][y][k];
    }
    
    
    double knightProbability(int n, int k, int r, int c) {
        // can make k oves
        // initial pos (r,c)
        // dp[i][j][k] represents probability of staying in from (i,j) having k moves
        vector<vector<vector<double>>> memo(n,vector<vector<double>>(n,vector<double>(k+1,0)));
        return solve(n,k,r,c,memo);
    }
};  
