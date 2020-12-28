// https://leetcode.com/problems/palindromic-substrings/

class Solution {
public:
    int countSubstrings(string str) {
        
        int n = str.size();
        
        int count = 0;
        
        // for odd length palindromes
        
        for(int mid = 0; mid < n; mid++){
            for(int x = 0; mid - x >= 0 && mid+x < n; x++){ // distance from mid
                if(str[mid-x] != str[mid+x]) break;
                else count++;
                    
            }
        }
        
        // even length palindromes
        
        for(int mid = 0; mid < n-1; mid++){
            for(int x = 1; mid - x + 1 >= 0 && mid + x < n; x++){
                if(str[mid-x+1] != str[mid+x]) break;
                else count++;
            }
        }
        
        return count; // O(n^2) Approach hai ye
    }
};
