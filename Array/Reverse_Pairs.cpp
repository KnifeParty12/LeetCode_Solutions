// https://leetcode.com/problems/reverse-pairs/submissions/

class Solution {
public:
    
    int mergo(vector<int> &arr ,int si, int mid, int ei){
        
        vector<int> temp((ei - si) + 1); // keep tracks of our sorted array
        
        int ans = 0;
        
        int j = mid;
        int i,k;
        for( i = si; i< mid; i++){
            while(j<=ei && arr[i] > 2LL * arr[j]) j++;
            ans += j - mid;
        }
        
        i = si, j = mid, k = 0;
        
        while(i < mid && j <=ei){
            if(arr[i] <= arr[j]) temp[k++] = arr[i++];
            else temp[k++] = arr[j++];           
        }
        
        while(i < mid) temp[k++] = arr[i++];
        while(j <= ei) temp[k++] = arr[j++];
        
        // copy back to array
        
        i = si;
        k = 0;
        while(i <= ei) arr[i++] = temp[k++];
        
        return ans;
    }
    
    
    
    int solve(vector<int> &arr, int si, int ei){
        if(si >= ei) return 0;
        
        int ans = 0;
        
        int mid = (si + ei) >> 1;
        
        ans += solve(arr,si,mid);
        ans += solve(arr,mid+1,ei);
        
        ans += mergo(arr,si,mid+1,ei);
        return ans;
    }
    
    
    int reversePairs(vector<int>& arr) {
        
        int n = arr.size();
        if(n == 0 || n == 1) return 0;
        
        // LOGIC
        // similar to inversion sort?
        return solve(arr, 0, n-1);
    }
};
