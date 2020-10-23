#define mod 1000000007
typedef long long ll;

ll dp[51][51][51];
vector<pair<int,int>> dir = {{0,-1},{-1,0},{1,0},{0,1}};

class Solution {
public:
    int solve(int &m, int &n, int k, int x, int y){

        if(x < 0 || x == m || y < 0 || y == n) return 1;
        if(!k) return 0;

        if(dp[x][y][k] != -1) return dp[x][y][k];
        
        ll temp = 0;
        for(int i = 0; i<4; i++){
            int nx = x + dir[i].first;
            int ny = y + dir[i].second;
            temp += solve(m,n,k-1,nx,ny);
            if(temp >= mod) temp -= mod;
        }
        dp[x][y][k] = temp;
        return dp[x][y][k];
    }
    
    
    int findPaths(int m, int n, int N, int i, int j) {
        
        if(i < 0 || i >= m || j < 0 || j>=n) return 0;
        
        memset(dp, -1, sizeof dp);
        return solve(m,n,N,i,j);
        
    }
};
