
// https://leetcode.com/problems/parallel-courses-ii/

#define pb push_back

class Solution {
public:

    vector<int> adj[16];
    int sz;
    int mx;
    int dp[1<<16];
    
    vector<int> get_indeg(int mask){
    
        vector<int> indeg(sz,0);
        for(int i = 0; i<sz; i++){
            if(!(mask & (1<<i))){
                for(auto it : adj[i]) indeg[it]++;
            }
        }
        return indeg;
    }
    
    int get_course_with_indeg_0(int mask, vector<int> &indeg){
        
        int x = 0;
        
        for(int i = 0; i<sz; i++){
            if(!(mask & (1<<i)) && indeg[i] == 0) x|=(1<<i);
        }
        return x;
    }
    
    int cnt_possible_completions(int mask){
        
        int cnt = 0;
        for(int i = 0; i<sz; i++){
            if(mask & (1<<i)) cnt++;
        }
        return cnt;
    }
    
    
    int solve(int mask){
        
        if(mask == (1<<sz) - 1) return 0; // all alloted
        
        if(dp[mask]!= -1) return dp[mask];
        
        vector<int> indeg = get_indeg(mask); // get current indegree of remaining courses
        int submask = get_course_with_indeg_0(mask,indeg);
        int cnt = cnt_possible_completions(submask);
        
        if(cnt <= mx) dp[mask] = 1 + solve(mask | submask);   
        
        else{
            int res = INT_MAX;
            for(int i = submask; i>0; i = submask &(i-1)){ // setting of 1 bit at a time in submask starting from the rightmost bit then checking if == k
                if(mx == cnt_possible_completions(i))
                    res = min(res,1 + solve(mask | i));
            }
             dp[mask] = res;
        }
        return dp[mask];
    }
    
    int minNumberOfSemesters(int n, vector<vector<int>>& dependencies, int k) {
        
        sz = n;
        mx = k;
        for(int i = 0; i<dependencies.size(); i++){
            int f = dependencies[i][0] - 1;
            int s = dependencies[i][1] - 1;
            adj[f].pb(s);
        }
        memset(dp, -1, sizeof dp);
        
        // steps 
        // create adjacency list
        // now we create a mask of length n where ith bit represents that particular course
        // if ith bit is set then we have already done that course
        // now for a particular mask we gotta find unset courses with indeg == 0
        // count such courses if > k  then need to choose from that particular submask otherwise gucci
        
        return solve(0); // no course done yet
    }
};
