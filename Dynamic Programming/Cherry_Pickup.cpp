// https://leetcode.com/problems/cherry-pickup/

class Solution {
public:
    
    int dp[50][50][50]; // dp[r1][c1][c2]
    int n;
    
    int solve(vector<vector<int>> &arr, int r1, int c1,int c2){
        
        int r2 = r1 + c1 - c2;
        if(r1 == n-1 && c1 == n-1) return arr[r1][c1]; // reached end point
        if(r1 >=n || r2>=n || c2>=n || c1>=n || arr[r1][c1] == -1 || arr[r2][c2] == -1)
            return INT_MIN; // out of bounds or thorny boi
        
        if(dp[r1][c1][c2]!= -1) return dp[r1][c1][c2];
        
        // now the 2 peeps got intotal 4 options
        // p1 & p2 go right -> dp[r1][c1+1][c2+1]
        // p1 & p2 go down -> dp[r1+1][c1][c2]
        // p1 R and p2 D -> dp[r1][c1+1][c2]
        // p1 D and p2 R -> dp[r1+1][c1][c2+1]
        
        int res = arr[r1][c1];
        if(c1!= c2) res+=arr[r2][c2]; // people on different coordinates
        
        res += max({solve(arr,r1,c1+1,c2+1),solve(arr,r1+1,c1,c2),
                   solve(arr,r1,c1+1,c2),solve(arr,r1+1,c1,c2+1)});
        
        dp[r1][c1][c2] = res;

        return dp[r1][c1][c2];
    }
    
    
    int cherryPickup(vector<vector<int>>& arr) {
        
         n = arr.size();
    
        memset(dp,-1,sizeof dp);
        return max(0,solve(arr,0,0,0));
        
    }
};
