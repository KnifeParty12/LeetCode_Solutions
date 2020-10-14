#define pb push_back
int v;
vector<bool> visited(101);
class Solution {
public:
    
    
    bool solve(int sv,vector<int> adj[]){
        
        vector<bool> visited(v,false);
        unordered_set<int> s[2];
        s[0].insert(sv);
        visited[sv] = true;
        vector<int> pending;
        pending.pb(sv);
        
        while(!pending.empty()){
            int curr = pending.back();
            pending.pop_back();
            int currset = (s[0].count(curr) > 0) ? 0 : 1;
            
            for(auto it : adj[curr]){
                if(s[0].count(it) == 0 && s[1].count(it) == 0){
                    visited[it] = true;
                    s[1 - currset].insert(it);
                    pending.pb(it);
                }
                else if(s[currset].count(it) > 0) return false;
            }
        }
        return true;
        
    }
    
    
    bool isBipartite(vector<vector<int>>& graph) {
        
        v = graph.size();
        
        vector<int> adj[v];
        for(int i = 0; i<v; i++) visited[i] = false;

        for(int i = 0; i<v; i++){
            for(int j = 0; j<graph[i].size(); j++){
                adj[i].pb(graph[i][j]);
                adj[graph[i][j]].pb(i);
            }
        }
        
        for(int i = 0; i<v; i++){
            if(!visited[i] && !solve(i,adj)) return false;
        }
        return true;
    }
};
