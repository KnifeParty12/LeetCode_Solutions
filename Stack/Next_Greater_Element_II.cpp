//https://leetcode.com/problems/next-greater-element-ii/

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& arr) {
        
        int n = arr.size();
        if(n == 0) return {};
        
        vector<int> res(n);
        stack<int> s;
        for(int i = n-1; i>=0; i--) s.push(arr[i]);
        
        for(int i = n-1; i>=0; i--){
            while(!s.empty() && s.top() <= arr[i]) s.pop(); // checks for left greater element
            if(s.empty()) res[i] = -1;
            else res[i] = s.top();
            s.push(arr[i]); // for right greater element
        }
        return res;
    }
};
