/*
https://leetcode.com/problems/flood-fill/
*/

vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};
int m,n;

class Solution {
public:
    
    void dfs(vector<vector<int>>& image,int x,int y,vector<vector<bool>> & visited){
        
        visited[x][y] = true;
        
        for(int i = 0; i<4; i++){
            int nx = x + dir[i].first;
            int ny = y + dir[i].second;
            if(nx < 0 || nx == m || ny < 0 || ny == n) continue;
            if(!visited[nx][ny] && image[nx][ny] == image[x][y]) dfs(image,nx,ny,visited);
        }
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        
         m = image.size();
         n = image[0].size();

        vector<vector<bool>> visited(m,vector<bool>(n,false));    
        dfs(image,sr,sc,visited);
        
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(visited[i][j])image[i][j] = newColor;
            }
        }
        
        return image;
        }
};
