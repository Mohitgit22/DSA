class Solution {
public:
    int solve(vector<int>& nums, int n, vector<int>& dp){
        if(n-1 == 0) return nums[0];

        if(n -1 < 0) return 0;
         
         if(dp[n]!= -1)  return dp[n];

        int pick = nums[n-1] + solve(nums, n-2, dp);
        int notpick = solve(nums, n-1, dp);
        
        
        dp[n] =  max(pick, notpick);
        return dp[n];
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> dp(n+1, -1);
        return solve(nums, n, dp);
    }
};