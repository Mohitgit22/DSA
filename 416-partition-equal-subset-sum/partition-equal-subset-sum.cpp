class Solution {
public:
    bool solve(vector<int>& nums, int t, int cur_sum, int ind,vector<vector<int>> & dp){
        if(cur_sum == t) return true;

        if(ind <= 0) return false;

        if(dp[ind][cur_sum]!= -1) return dp[ind][cur_sum];

        bool notpick = solve(nums, t, cur_sum, ind-1, dp);

        bool pick = false;
        if(cur_sum + nums[ind-1] <= t){
            pick = solve(nums, t, cur_sum + nums[ind-1], ind-1, dp);
        }

        return dp[ind][cur_sum] = pick || notpick;
    }


    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);

        if(sum %2 != 0)
        return false;
        
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(sum+1, -1));
        return solve(nums, sum/2, 0, n, dp);
    }
};