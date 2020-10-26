typedef long long ll;

class Solution {
public:
    int subarraysDivByK(vector<int>& arr, int k) {
        
        int n = arr.size();
        unordered_map<int,int> hash; // map of remainders and cnt's
        
        hash[0] = 1; // considering whole array sum to be divisible
        ll prefix = 0;
        int ans = 0;
        for(int i = 0; i<n; i++){
            prefix+= arr[i];
            int rem = prefix % k;
            if(rem < 0) rem+=k;
            if(hash.count(rem))ans+= hash[rem];
            hash[rem]++;
        }
        return ans;
    }
};
