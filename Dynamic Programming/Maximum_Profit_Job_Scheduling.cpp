// https://leetcode.com/problems/maximum-profit-in-job-scheduling/submissions/

class Solution {
    public:
    
    struct triplet{  
    int start;
    int end;
    int profit;    
};

   
    int search(const vector<triplet> &job, int index){
    
        int lo = 0, hi = index-1;
        while(lo<=hi){
            int mid = (lo + hi) >> 1;
            if(job[mid].end <= job[index].start){
                if(job[mid+1].end <= job[index].start) lo = mid + 1;
                else return mid;
            }
            else hi = mid-1;
        }
        return -1;
    }

    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        
        int n = startTime.size();
        vector<triplet> job(n);
        
        for(int i = 0; i<n; i++){
            job[i].start = startTime[i];
            job[i].end = endTime[i];
            job[i].profit = profit[i];
        }
        
        sort(job.begin(),job.end(),[](const triplet &a, const triplet &b)
             {
                 return a.end < b.end;
                 });
        
        vector<int> dp(n,0);
        dp[0] = job[0].profit; // only 1 job available
        

        for(int i = 1; i<n; i++){
            int p1 = job[i].profit; // taking job i 
            int l = search(job,i); // searching for most optimum using binary_search
            if(l!= -1) p1 += dp[l];
            dp[i] = max(dp[i-1],p1);
        }
        return dp[n-1];
    }
};
