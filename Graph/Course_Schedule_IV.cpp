// https://leetcode.com/problems/course-schedule-iv/submissions/

#define pb push_back

class Solution {
public:    
    
    int f,s;
    
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
            
            // similar to floyd warshall
        vector<vector<int>> adj(n,vector<int>(n,0));
        for(int i = 0; i<prerequisites.size(); i++){
             f = prerequisites[i][0];
             s = prerequisites[i][1];
            adj[f][s] = 1;
        }
        
        for(int k = 0; k < n; k++){
            for(int i = 0; i<n; i++){
                for(int j = 0; j<n; j++){
                    if(adj[i][k] && adj[k][j]) adj[i][j] = 1;
                }
            }
        }
        
        int q = queries.size();
        vector<bool> res(q,false);
        for(int i = 0; i<q; i++){
            f = queries[i][0];
            s = queries[i][1];
            if(adj[f][s]) res[i] = true;
        }
        
        return res;
    }
};
