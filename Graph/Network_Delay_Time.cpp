// https://leetcode.com/problems/network-delay-time/submissions/

#define MAX 101
#define PII pair<int,int> 
#define pb push_back

class Solution {
public:
    
    vector<PII> adj[MAX];
    int dist[MAX];
    
    void dijkstra(int sv,int n){
        
        for(int i = 1; i<=n; i++) dist[i] = INT_MAX;
        set<PII> pq;
        dist[sv] = 0; // set initial dist
        pq.insert({0,sv});
        
        while(!pq.empty()){
            int curr = pq.begin()->second;
            int d = pq.begin()->first;
            pq.erase(pq.begin());
            
            if(dist[curr] < d) continue; // no use
            
            for(PII pr : adj[curr]){
                int v = pr.first;
                int nd = d + pr.second;
                if(nd < dist[v]){
                    pq.erase({dist[v],v});
                    dist[v] = nd;
                    pq.insert({nd,v});
                }
            }
        }
    
    }
        
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        
        int sz = times.size();
        int f,s,w;
        
        for(int i = 0; i<=N; i++) adj[i].clear();
        
        for(int i = 0; i<sz; i++){
            f = times[i][0];
            s = times[i][1];
            w = times[i][2];
            adj[f].pb({s,w}); // directed graph
        }
          
        dijkstra(K,N);
        
        int ans = INT_MIN;
        for(int i = 1; i<=N; i++){
            if(dist[i] == INT_MAX) return -1;
            ans = max(ans,dist[i]);
        }
        return ans;
    }
};
