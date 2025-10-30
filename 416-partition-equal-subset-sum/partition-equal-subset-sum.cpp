class Solution {
public:
    // bool solve(vector<int>& nums, int t, int cur_sum, int ind,vector<vector<int>> & dp){
    //     if(cur_sum == t) return true;

    //     if(ind <= 0) return false;

    //     if(dp[ind][cur_sum]!= -1) return dp[ind][cur_sum];

    //     bool notpick = solve(nums, t, cur_sum, ind-1, dp);

    //     bool pick = false;
    //     if(cur_sum + nums[ind-1] <= t){
    //         pick = solve(nums, t, cur_sum + nums[ind-1], ind-1, dp);
    //     }

    //     return dp[ind][cur_sum] = pick || notpick;
    // }


    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);

        if(sum %2 != 0)
        return false;
        
        sum = sum/2;
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(sum+1, false));

        for(int i = 0;i < n+1; i++){
            for(int j= 0; j < sum+1; j++){
               if(i == 0)
               dp[i][j]= false;

               if(j == 0)
               dp[i][j] = true;
            }
        }

        for(int i = 1; i < n+1; i++){
            for(int j = 1; j < sum+1; j++){
                if(nums[i-1] <= j){
                    dp[i][j] = dp[i-1][j-nums[i-1]] || dp[i-1][j];
                }
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        return dp[n][sum];
    }
};