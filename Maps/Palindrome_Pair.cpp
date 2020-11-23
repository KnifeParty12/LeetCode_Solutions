// https://leetcode.com/problems/palindrome-pairs/

#define pb push_back

class Solution {
public:
    
    bool check_palindrome(string &str){
        
        int n = str.length();
        int i = 0;
        int j = n-1;
        
        while(i < j){
            if(str[i++]!= str[j--]) return false;
        }
        return true;
    }

    vector<vector<int>> palindromePairs(vector<string>& words) {
        
        int n = words.size();
        if(n == 1) return {};
        
        unordered_map<string,int> hash;
        for(int i = 0; i<n; i++){
            string temp = words[i];
            reverse(temp.begin(),temp.end());
            hash[temp] = i;
        }
        
        vector<vector<int>> res;
        
        // need to check for "" coz it can be palindrome with every other palindrome
        if(hash.find("")!= hash.end()){
            for(int i = 0; i<n; i++){
                if(words[i] == "") continue;
                if(check_palindrome(words[i])) res.pb({hash[""],i}); // {"",self}
            }
        }
        
        for(int i = 0; i<n; i++){
            string str = words[i];
            for(int j = 0; j<str.size(); j++){
                string left = str.substr(0,j);
                string right = str.substr(j,str.size() - j);
                
                if(hash.find(left)!= hash.end() 
                   && check_palindrome(right) && hash[left]!= i){
                    res.pb({i,hash[left]});
                }
                
                if(hash.find(right)!= hash.end() 
                   && check_palindrome(left) && hash[right]!= i){
                    res.pb({hash[right],i});
                }
            }
        }
        return res;
    }
};
