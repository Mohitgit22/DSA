class Solution {
public:
    // int solve(vector<int>& nums, int n, vector<int>& dp){
    //     if(n-1 == 0) return nums[0];

    //     if(n -1 < 0) return 0;
         
    //      if(dp[n]!= -1)  return dp[n];

    //     int pick = nums[n-1] + solve(nums, n-2, dp);
    //     int notpick = solve(nums, n-1, dp);   
        
    //     dp[n] =  max(pick, notpick);
    //     return dp[n];
    // }

    int rob(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> dp(n+1, -1);

        dp[0] = 0;
        dp[1] = nums[0];
        // dp[2] = max(nums[0], nums[1]);

        for(int i = 2; i <= n; i++){
           int pick = nums[i-1] + dp[i-2];
           int notpick = dp[i-1];

           dp[i] = max(pick, notpick) ;
        }
        
        return dp[n];
    }
};