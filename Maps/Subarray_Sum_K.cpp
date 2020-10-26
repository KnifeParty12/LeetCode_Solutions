class Solution {
public:
    int subarraySum(vector<int>& arr, int k) {
        
        unordered_map<int,int> hash;
        hash[0]++; // if whole subarray sum is divisible
        int n =arr.size();
        int cnt = 0;
        int prefix = 0;
        for(int i = 0; i<n; i++){
            prefix+=arr[i];
            int x = prefix - k;
            cnt+= hash[x];
            hash[prefix]++;
        }
        return cnt;
    }
};
