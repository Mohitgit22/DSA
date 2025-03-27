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


    int maxrob(vector<int>& nums, vector<int>& dp, int n){
        if( n < 0)
        return 0;

        if(n == 0)
        return dp[n];

        if(dp[n] != -1)
        return dp[n];

        int pick = nums[n] + maxrob(nums, dp, n-2);
        int notpick = maxrob(nums, dp, n-1);

        dp[n] = max(pick, notpick);
        return dp[n];
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        
        // return maxrob(nums, n-1);
        vector<int> dp(n,-1);
        dp[0] = nums[0];

        return maxrob(nums, dp, n-1);

        // vector<int> dp(n+1, -1);
        // return top_down(nums, n, dp);
        // return bottom_up(nums, n, dp);
    }
};