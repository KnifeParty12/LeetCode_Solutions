// https://leetcode.com/problems/candy/submissions/

class Solution {
public:
    int candy(vector<int>& ratings) {
        
        int n = ratings.size();
        // LOGIC
        // initally give everyone 1 candy
        // then first pass ->  right check
        // second pass left check
        
        vector<int> arr(n,1);
        int sum = 0;
        // right check 
        // start with end
        for(int i = n-2; i>=0; i--){
            if(ratings[i] > ratings[i+1]) arr[i] = arr[i+1] + 1;
        }
        
        // left check 
        // start with left
        for(int i = 1; i<n; i++){
           if(ratings[i] > ratings[i-1] && arr[i] <= arr[i-1]) arr[i] = arr[i-1] + 1; 
        }

        for(int i = 0; i<n; i++) sum += arr[i];
        
        return sum;
        
    }
};
