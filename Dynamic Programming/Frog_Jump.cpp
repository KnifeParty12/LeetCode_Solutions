// https://leetcode.com/problems/frog-jump/submissions/

class Solution {
public:
    
    int n,target;
    int dp[1101][1101]; // dp[i] represents if we can reach end from this index
    // maybe we need the last jump as a state too
    
    int search(vector<int> &arr,int x,int start){
        int lo = start+1;
        int hi = n-1;
        while(lo<=hi){
            int mid = (lo + hi) >> 1;
            if(arr[mid] == x) return mid;
            else if(arr[mid] > x) hi = mid-1;
            else lo = mid + 1;
        }
        return -1;
    }
    

    bool solve(int curr,int k,int indx,vector<int> &stones){ // k represents last jump
        
        if(indx == n-1) return dp[indx][k] = true;
        
        if(dp[indx][k]!= -1) return dp[indx][k];
        
        // OPTIONS -> k-1,k,k+1
        bool res = false;
        
        int nxt_indx;
        
        if((k-1)!= 0){ // 0 jump loop
            nxt_indx = search(stones,curr + k -1,indx);
            if(nxt_indx!= -1) res |= solve(curr+(k-1),k-1,nxt_indx,stones);  // k-1
        } 


        nxt_indx = search(stones,curr+k,indx);
        if(nxt_indx != -1) res |= solve(curr+k,k,nxt_indx,stones); // k-1
          
        
        nxt_indx = search(stones,curr + k + 1,indx);          
        if(nxt_indx!= -1) res |= solve(curr+k+1,k+1,nxt_indx,stones); // k-1   
        
        return dp[indx][k] = res;
    }
    
    
    
    
    bool canCross(vector<int>& stones) {
        
        n = stones.size();
        if(stones[1]!= 1) return false;
        target = stones[n-1];
        memset(dp,-1,sizeof dp);
        return solve(1,1,1,stones);
    }
};
