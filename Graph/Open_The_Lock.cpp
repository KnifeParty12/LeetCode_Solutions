// https://leetcode.com/problems/open-the-lock/submissions/
#define pb push_back

class Solution {
public:
    
    
    vector<string> solve(string str){
        
        vector<string> res;
        
        for(int i = 0; i<4; i++){ //increment
            string temp = str;
            if(temp[i] == '9') temp[i] = '0';  
            else temp[i] = str[i] + 1;
            res.pb(temp);
        }
        
        for(int i = 0; i<4; i++){ //increment
            string temp = str;
            if(temp[i] == '0') temp[i] = '9';  
            else temp[i] = str[i] - 1;
            res.pb(temp);
        }
        
        return res;
    }
    
    
    int openLock(vector<string>& deadends, string target) {
        
        int n = deadends.size();
        unordered_set<string> dead;
        
        for(int i = 0; i<n; i++){
            if(deadends[i] == "0000") return -1;
            dead.insert(deadends[i]);  
        }      
        
        // LOGIC
        // bruh kinda tired by now let's see
        // BFS coz minimize yea?
        // set for visited
        
        queue<pair<string,int>> pq;
        unordered_set<string> visited;
        
        visited.insert("0000");
        pq.push({"0000",0});
        int ans = -1;
        
        while(!pq.empty()){
            string curr = pq.front().first;
            int d = pq.front().second;
            if(curr == target){
                ans = d;
                break;
            }
            pq.pop();
            // we got 8 options in total
            // +- 1st digit ... till 4th digit
            vector<string> options = solve(curr);
            for(int i = 0; i<options.size(); i++){
                if(visited.find(options[i]) == visited.end() &&
                   dead.find(options[i]) == dead.end())
                {
                    visited.insert(options[i]);
                    pq.push({options[i],d+1});
                }
            }
        }
        return ans;
    }
};
