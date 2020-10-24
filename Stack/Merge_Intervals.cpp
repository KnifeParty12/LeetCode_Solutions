#define pb push_back

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& a) {
        
        int n = a.size();
        if(n == 0) return {};
        
        sort(a.begin(),a.end(),[](const vector<int> &x,const vector<int> &b){
           return x[0] < b[0];  
        });
        
        stack<vector<int>> s;
        s.push(a[0]);
        
        for(int i = 1; i<n; i++){
            vector<int> curr = s.top();
            
            if(curr[1] < a[i][0]) s.push(a[i]);
            
            else if(curr[1] < a[i][1]){
                curr[1] = a[i][1];
                s.pop();
                s.push(curr);
            }   
        }
        
        vector<vector<int>> res;
        while(!s.empty()){
            res.pb(s.top());
            s.pop();
        }
        return res;
    }
};
