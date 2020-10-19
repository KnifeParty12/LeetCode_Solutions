//https://leetcode.com/problems/possible-bipartition/


#define pb push_back
vector<int> adj[2001];
class Solution {
public:
    bool biparty(int sv,vector<bool> &visited){

        unordered_set<int> s[2];
        visited[sv] = true;
        s[0].insert(sv);
        vector<int> pending;
        pending.pb(sv);
        while(!pending.empty()){
            int curr = pending.back();
            pending.pop_back();
            int currset = (s[0].count(curr)) ? 0 : 1;
            for(auto it : adj[curr]){
              if(s[0].count(it) == 0 && s[1].count(it) == 0){
                  visited[it] = true;
                  s[1-currset].insert(it);
                  pending.pb(it);
              }
                else if(s[currset].count(it)) return false;
            }
        }
        return true;
    }
    
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        
        int e = dislikes.size();
        if(e == 0) return true;
        for(int i = 0; i<=N; i++)adj[i].clear();
        int f,se;
        for(int i = 0; i<e; i++){
            f = dislikes[i][0];
            se = dislikes[i][1];
            adj[f].pb(se);
            adj[se].pb(f);
        }
        vector<bool> visited(N+1,false);
        // Applying Bipartite boi
        for(int i = 1; i<=N; i++){
            if(!visited[i] && !biparty(i,visited)) return false;
        }
        return true;   
    }
};
