// https://leetcode.com/problems/minimum-jumps-to-reach-home/

#define pb push_back

class Solution {
public:
    
    
    
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        
        int n = forbidden.size();
        if(x == 0) return 0;
        // UPPER-BOUND would be max reach ahead of x --> 6000
         // max limit;
        unordered_set<int> no;
        for(int i = 0; i<n; i++) no.insert(forbidden[i]);
        n = 6000;
        
        queue<vector<int>> pq;
        set<pair<int,int>> visited; // important
        pq.push({0,0,0}); // index,jumps,back-jumps
        visited.insert({0,0});
        
        while(!pq.empty()){
            int curr = pq.front()[0];
            int d = pq.front()[1];
            int bj = pq.front()[2];
            pq.pop();
            
            if(curr == x) return d;
            
            int f = curr + a;
            int bc = curr - b;
        
            if(bj != 1 and bc > 0 and visited.find({bc,bj}) == visited.end()
               and no.find(bc) == no.end()){
                visited.insert({bc,1});
                pq.push({bc,d+1,1});
            }
            
            if(f < n && visited.find({f,bj}) == visited.end() && no.find(f) == no.end()){
                visited.insert({f,0});
                pq.push({f,d+1,0});
            }
        }
        return -1;
    }
};
