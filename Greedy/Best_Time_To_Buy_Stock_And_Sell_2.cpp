class Solution {
public:
    int maxProfit(vector<int>& price) {
        
        int n = price.size();
        if(n < 2) return 0;
        set<int> s;
        int profit = 0;
        
        for(int i = 1; i<n; i++){
            if(i == n-1){
                if(price[i] > price[i-1])s.insert(i);
            }
            else{
                if(price[i] > price[i-1] && price[i] >= price[i+1]) s.insert(i);
            }
        }
        
        if(s.size() == 0) return 0;
        
        
        int i = 0;
        while(i < n && !s.empty()){
            int f_peak = *s.begin();
            int temp = INT_MAX;
            while(i < f_peak){
                if(price[i] < temp) temp = price[i];    
                i++;
            }
            profit += price[f_peak] - temp;
            s.erase(s.begin());
        }
        
        return profit;
    }
};
