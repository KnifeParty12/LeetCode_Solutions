// https://leetcode.com/problems/score-of-parentheses/submissions/

class Solution {
public:
    
    vector<int> ending;
    
    
    int helper(string &str, int lo, int hi){
        if(lo == hi-1) return 1;
        
        int mid = ending[lo];
        if(mid == hi) return 2 * helper(str,lo+1,hi-1);
        else return helper(str,lo,mid) + helper(str,mid+1,hi);
    }
    
    
    int scoreOfParentheses(string str) {
        
        int n = str.length();
        ending.resize(n,0);
        
        stack<int> s;
        for(int i = 0; i<n; i++){
            if(str[i] == ')'){
                int t = s.top();
                s.pop();
                ending[t] = i;
            }
            else s.push(i);
        }
        
        return helper(str,0,n-1);
        
    }
};
