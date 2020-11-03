// https://leetcode.com/problems/as-far-from-land-as-possible/

vector<pair<int,int>> dir = {{1,0},{0,1},{-1,0},{0,-1}};

class Solution {
public:
    
    bool isSafe(int &i,int &j, int &n){
        if(i < 0 || i>=n || j < 0 || j>=n) return false;
        return true;
    }
    
    int maxDistance(vector<vector<int>>& grid) {
        
        int n = grid.size();
     
        int ans = -1;
        //LOGIC reverse engineer it 
        // try to find all closest water blocks from each land 
        // and then apply bfs

        queue<pair<int,int>> pq;
        vector<vector<bool>> visited(n,vector<bool>(n,false));
        
        for(int i = 0; i<n; i++){ // push lands in
            for(int j = 0; j<n; j++) {
                if(grid[i][j] == 1) { 
                pq.push({i,j});
                visited[i][j] = true;
            }
            }
        }
        
        if(pq.size() == n*n || pq.size() == 0) return -1;
        
        
        while(!pq.empty()){
            ans++;
            int sz = pq.size();
            while(sz-- ){    
                int cx = pq.front().first;
                int cy = pq.front().second;
                pq.pop();
                
                for(int j = 0; j<4; j++){
                    int nx = cx + dir[j].first;
                    int ny = cy + dir[j].second;
                    if(isSafe(nx,ny,n) && !visited[nx][ny]){
                        pq.push({nx,ny});
                        visited[nx][ny] = true;
                    }
                }
            }
        }
        return ans;
    }
};
