class Solution {
public:
    
    
    int maxProfit(vector<int>& price) {
        
        int n = price.size();
        if(n < 2) return 0;
        
         vector<int> right_max(n);
         right_max[n-1] = -1;
         int mx = price[n-1];
        
        for(int i = n-2; i>=0; i--){
            if(price[i] < mx){
                right_max[i] = mx;
            }
            else{
                mx = price[i];
                right_max[i] = -1;
            }
        }
        
        int profit = 0;
        for(int i = 0; i<n; i++){
            if(right_max[i]!= -1){
                profit = max(profit,right_max[i] - price[i]);
            }
        }
        return profit;
    }
};
