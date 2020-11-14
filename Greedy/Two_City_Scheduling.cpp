// https://leetcode.com/problems/two-city-scheduling/submissions/

class Solution {
public:

    static bool cmp( const vector<int> &a, vector<int>&b){
        return abs(a[0] - a[1]) > abs(b[0]-b[1]);
    }
    
    
    int twoCitySchedCost(vector<vector<int>>& costs) {
        
        int n = costs.size();
        sort(costs.begin(),costs.end(),cmp);
        // sorting on the basis of difference between costA - costB
        
        int ans = 0;
        int pa = 0;
        int pb = 0;
        
        int i = 0;
        
        while(i < n){
            
            if(pa == n/2){
                ans += costs[i][1];
                pb++;
            }
            
            else if(pb == n/2){
                ans+= costs[i][0];
                pa++;
            }
            
            else if(costs[i][0] >= costs[i][1]){
                ans += costs[i][1];
                pb++;
            }
            
            else{
                ans += costs[i][0];
                pa++;
            }
            i++;
        }
        return ans;
    }
};
