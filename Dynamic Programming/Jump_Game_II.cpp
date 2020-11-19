// https://leetcode.com/problems/jump-game-ii/

class Solution {
public:
    int jump(vector<int>& a) {
        if(a.size() == 1) return 0;
        int jumps = 0;
        int n = a.size();
        pair<int,int> it = {0,0};

        
        while(1){
            jumps++;
            int reach = -1;
            for(int i = it.first; i<=it.second; i++){
                reach = max(reach,i + a[i]);
                if(reach>=n-1) return jumps;
            }   
                it = {it.second+1,reach};
                if(it.first > it.second) return -1;
        }
        
    }
};
