class Solution {
public:
    int recur(vector<int>& nums, int n, vector<int>& dp){
        if(n < 0) return 0;

        if(n == 0) return nums[0];

        if(dp[n] != -1) return dp[n];

        int steal = nums[n] + recur(nums, n-2, dp);
        int skip = recur(nums, n-1, dp);

        dp[n] = max(steal, skip);
        return dp[n];
    }

    
    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n == 1) return nums[0];

        vector<int> dp1(n, -1), dp2(n, -1);
 
        //exclude last house
        int case1 = recur(nums, n-2, dp1);
        //exclude first house
        vector<int> nums2(nums.begin() + 1, nums.end());
        int case2 = recur(nums2, n-2, dp2);

        return max(case1, case2);
    }
};