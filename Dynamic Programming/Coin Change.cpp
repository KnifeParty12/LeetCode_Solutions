/*
https://leetcode.com/problems/coin-change/
*/

#define MAX 10005

class Solution {
public:
    int coinChange(vector<int>& coins, int val) {
        
        int n = coins.size();
        if(val == 0) return 0;
        
        queue<pair<int,int>> pq;
        pq.push({val,0});
        
        vector<bool> visited(MAX,false);
        visited[val] = true;
        
        while(!pq.empty()){

            int curr = pq.front().first;
            int d = pq.front().second;
    //        cout<<curr<<endl;
            pq.pop();
            
            if(!curr) return d;
            
            for(int i = 0; i<n; i++){
                int target = curr - coins[i];
                if(target >= 0 && !visited[target]){
                    visited[target] = true;
                    pq.push({target,d+1});
                } 
            }
        
        }
        return -1;
    }
};
