// https://leetcode.com/problems/longest-repeating-character-replacement/submissions/
#define pb push_back

class Solution {
public:
    int characterReplacement(string str, int k) {
        
        int n = str.length();
        if(k >= n) return n;

        unordered_map<char,int> hash;
        int mx_cnt = 0;
        // start window
        int lo = 0;
        int hi = 0;
        
        int ans = 0;
        
        while(hi < n){
        
            hash[str[hi]]++;
            mx_cnt = max(mx_cnt,hash[str[hi]]);
            
            if((hi - lo + 1) - mx_cnt > k){
             hash[str[lo]]--;
             lo++;
            }
            
            ans = max(ans,(hi - lo) + 1);
            hi++;
        }
        return ans;
    }
};
