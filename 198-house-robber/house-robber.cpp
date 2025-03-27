class Solution {
public:
    //recursion
    // int maxrob(vector<int>& nums, int n){
    //     if(n == 0)
    //     return nums[0];

    //     if(n < 0)
    //     return 0;

    //     int pick = nums[n] + maxrob(nums, n-2);
    //     int notpick = maxrob(nums, n-1);

    //     return max(pick, notpick);
    // }

      
      //top_down
    // int maxrob(vector<int>& nums, vector<int>& dp, int n){
    //     if( n < 0)
    //     return 0;

    //     if(n == 0)
    //     return dp[n];

    //     if(dp[n] != -1)
    //     return dp[n];

    //     int pick = nums[n] + maxrob(nums, dp, n-2);
    //     int notpick = maxrob(nums, dp, n-1);

    //     dp[n] = max(pick, notpick);
    //     return dp[n];
    // }

    //bottom_up
    // int bottom_up(vector<int>& nums, int n, vector<int>& dp){
        
    //     dp[0] = 0;
    //     dp[1] = nums[0];

    //     for(int i = 2; i <= n; i++){
    //         int steal = nums[i-1] + dp[i-2];
    //         int skip = dp[i-1];

    //         dp[i] = max(steal, skip);
    //     }
    //     return dp[n];
    // }


    //space_optimized_bottom_up
    int bottom_up(vector<int>& nums, int n, vector<int>& dp){
        int prev2 = 0;
        int prev1 = nums[0];
        int ans = -1;

        for(int i = 2; i <= n; i++){
            int steal = nums[i-1] + prev2;
            int skip = prev1;
            // dp[i] = max(steal, skip);
            ans = max(steal, skip);
            
            prev2 = prev1;
            prev1 = ans;
        }
        return ans;
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
         if(n<=1)
         return nums[0];
        // return maxrob(nums, n-1);

        // vector<int> dp(n,-1);
        // dp[0] = nums[0];
        // return maxrob(nums, dp, n-1);
        

        vector<int>dp(n+1);
        return bottom_up(nums, n, dp);
    }
};