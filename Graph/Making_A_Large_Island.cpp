// https://leetcode.com/problems/making-a-large-island/

class Solution {
public:

    bool visited[51][51];
    int m,n;
    int color[51][51];
    int color_size[5000];
    vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
    
    int dfs(vector<vector<int>>& arr, int x, int y,int col){
        
        color[x][y] = col; // mark particular point with the current color
        visited[x][y] = true; // mark visited
        
        int ans = 0;
        for(int i = 0; i<4; i++){
            int nx = x + dir[i][0];
            int ny = y + dir[i][1];
            if(nx >= 0 && nx < m && ny >=0 && ny < n 
               && !visited[nx][ny] && arr[nx][ny] == 1){ 
                ans += dfs(arr,nx,ny,col);
                
            }
        }
        return 1 + ans; // considering current point
    }
    
    int getmaxpossible(vector<vector<int>>& arr, int x, int y){
        
        int ans = 0;
        
        unordered_set<int> checked;
        for(int i = 0; i<4; i++){
            int nx = x + dir[i][0];
            int ny = y + dir[i][1];
            if(nx >= 0 && nx < m && ny >=0 && ny < n && arr[nx][ny] == 1){
                int col = color[nx][ny];
                if(checked.find(col) == checked.end()){
                ans += color_size[col];
                }
                checked.insert(col); // keep check if reusing current color again or not
            }
        }
        return 1 + ans; // flipping current zero
    }
    
    
    int largestIsland(vector<vector<int>>& arr) {
     
         m = arr.size();
         n = arr[0].size();

        memset(visited,false,sizeof visited);
        memset(color,0,sizeof color);
        memset(color_size,0,sizeof color_size);

        int counter = 1; // current color
        int temp = 0;
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(!visited[i][j] && arr[i][j] == 1){
                    int sz = dfs(arr,i,j,counter);
                    temp = max(temp,sz);
                    color_size[counter] = sz;
                    counter++;
                }
            }
        }
        
        int ans = 0;
        for(int i = 0; i< m; i++){
            for(int j = 0; j<n; j++){
                if(arr[i][j] == 0){ //check every potential 0
                    int sm = getmaxpossible(arr,i,j);
                    ans = max(ans,sm);
                }
            }
        }
        if(ans == 0) return temp; // if no zero found
        return ans;
    }
};
