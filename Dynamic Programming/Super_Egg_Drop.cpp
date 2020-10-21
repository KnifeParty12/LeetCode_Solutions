class Solution {
public:
    int superEggDrop(int k, int n) { // k eggs n floors
    
        vector<vector<int>> dp(k+1,vector<int> (n+1,0));
        
        for(int i=0;i<=k;i++) dp[i][0]=0,dp[i][1]=1;
      
        for(int i=0;i<=n;i++) dp[0][i]=0,dp[1][i]=i;
    
        
        for(int i=2;i<=k;i++)
        {
            for(int j=2;j<=n;j++)
            {    
                int l=1,h=j,temp=0,ans=1e5;
                 while(l<=h)
                 {
                
                     int mid=(l+h)/2;
                     int left= dp[i-1][mid-1]; //egg broken check for down floors of mid
                     int right= dp[i][j-mid];  // not broken check for up floors of mid
                    
                     temp=1+max(left,right); //store max of both 
                    
                     if(left<right) l=mid+1;
                     else h=mid-1;
        
                    ans=min(ans,temp);
                 }
                
                 dp[i][j]=ans;
            }
        }
        return dp[k][n];

        
    }
};
