// https://leetcode.com/problems/burst-balloons/

class Solution {
public:
    
    int dp[500][500];
    
    int solve(vector<int> & ballon, int start, int end){
        // base case
        if(start > end) return 0;
        
        if(dp[start][end]) return dp[start][end];
        int left = 1, right = 1;
        
        if(start - 1 >= 0) left = ballon[start-1];
        if(end+1 < ballon.size()) right = ballon[end+1];
        
        int res = 0;
        for(int i = start; i<=end; i++){
            res = max(res,
                      solve(ballon,start,i-1) + solve(ballon,i+1,end)
                      + ballon[i]*left*right); // last ballon to be burst
        }
        return dp[start][end] = res;
    }
    
    
    int maxCoins(vector<int>& a) {
        
        int n = a.size();
        if(n == 0) return 0;
    
        return solve(a,0,n-1);
    }
};
