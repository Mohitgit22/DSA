class Solution {
public:
    vector<vector<int>> dp;
    int k;
    int n;
    
    bool solve(int i, int sum, vector<int>& nums) {
        if (i >= n)
            return (sum == k / 2);
        
        if (dp[i][sum] != -1)
            return dp[i][sum];
        
        bool include = false;
        if (sum + nums[i] <= k / 2) {
            include = solve(i + 1, sum + nums[i], nums);
        }
        bool exclude = solve(i + 1, sum, nums);
        
        return dp[i][sum] = include || exclude;
    }
    
    bool canPartition(vector<int>& nums) {
        n = nums.size();
        k = 0;
        for (auto x : nums) {
            k += x;
        }
        if (k % 2 != 0) {
            return false;
        }
        dp.assign(n, vector<int>(k / 2 + 1, -1));
        return solve(0, 0, nums);
    }
};