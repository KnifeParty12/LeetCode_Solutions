vector<pair<int,int>> dir = {{-1,0},{1,0},{0,-1},{0,1},{-1,-1},{1,-1},{-1,1},{1,1}};

struct triplet{
    int x;
    int y;
    int d;
};

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        
        if(grid[0][0] == 1) return -1;
        
        queue<triplet> pq;
        vector<vector<bool>> visited(m,vector<bool>(n));
        
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(grid[i][j] == 1) visited[i][j] = true;
                else visited[i][j] = false;
            }
        }
        
        
        triplet init = {0,0,1};
        pq.push(init);
        visited[0][0] = true;
        triplet tp;
        
        while(!pq.empty()){
         
            tp = pq.front();
            int x = tp.x;
            int y = tp.y;
            int d = tp.d;
        
            if(x == m-1 && y == n-1) break;
            
            pq.pop();
            
            for(int i = 0; i<8; i++){
                int nx = x + dir[i].first;
                int ny = y + dir[i].second;
                
                if(nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                
                else if(!visited[nx][ny]){
                    visited[nx][ny] = true;
                    pq.push({nx,ny,d+1});
                }
            }   
        }
        
        if(tp.x == m-1 && tp.y == n-1) return tp.d;
        else return -1;
        
    }
};
