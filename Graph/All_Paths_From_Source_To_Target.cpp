// https://leetcode.com/problems/all-paths-from-source-to-target/submissions/

#define pb push_back

class Solution {
public:
    
    vector<int> adj[16];
    vector<vector<int>> res;

    void dfs(int sv, int ev,vector<int> temp){
       if(sv == ev){ // found a path
           temp.pb(sv);
           res.pb(temp);  
           return;
       }
        for(auto it : adj[sv]){
            temp.pb(sv);
            dfs(it,ev,temp);
            temp.pop_back();
        }
    }
    
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        
        int n = graph.size();
        for(int i = 0; i<n; i++) adj[i].clear();
        for(int i = 0; i<res.size(); i++) res[i].clear();
        
        for(int i = 0; i<n; i++){
            for(int j = 0; j<graph[i].size(); j++) adj[i].pb(graph[i][j]);
        }
        
        // LOGIC
        // Need to find all paths from 0 -> n-1
        
        
        vector<int> temp;
        dfs(0,n-1,temp);

        return res;
    }
};
