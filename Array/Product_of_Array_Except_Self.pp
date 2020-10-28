class Solution {
public:
    vector<int> productExceptSelf(vector<int>& arr) {
        
        int n = arr.size();
        vector<int> res(n);
        
        res[0] = 1;
        
        for(int i = 1; i<n; i++){ // store answer of left product
            res[i] = res[i-1]*arr[i-1];
        }
        
        int right = 1;
        for(int i = n-1; i>=0; i--){
            res[i] = res[i]*right;
            right *= arr[i];
        }   
        return res;
    }
};
