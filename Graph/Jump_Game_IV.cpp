// https://leetcode.com/problems/jump-game-iv/submissions/

#define pb push_back
#define pii pair<int,int>

class Solution {
public:
    int minJumps(vector<int>& arr) {
          
        unordered_map<int,vector<int>> hash;
        int n=arr.size(); 
        for(int i=0;i<n;++i) hash[arr[i]].pb(i); // OCCURRENCES
    
        vector<bool> visited(n,false);
        visited[0]=1;
        queue<pii> pq;
        pq.push({0,0});
        int res = INT_MAX;
        
        while(!pq.empty()){
        
            int curr = pq.front().first;    
            int d=pq.front().second;
            pq.pop();
            
            if(curr == n-1) return d;    

    		if(curr > 0 && !visited[curr-1]) {
    			pq.push({curr-1,d+1});
    			visited[curr-1]= true;
    		}
            
    		if(curr+1 <n && !visited[curr + 1]) {
    			pq.push({curr+1,d+1});
    			visited[curr+1]=true;
    		}
            
    		for(int v:hash[arr[curr]])
    			if(!visited[v]){
    				pq.push({v,d+1});
    				visited[v]=true;
    			}
            hash[arr[curr]]={}; // important step
    }
    return res;
}

};
