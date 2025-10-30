class Solution {
public:
    int solve(vector<int>& dp, int n){
        if(n <= 2){
            dp[n] = n;
            return dp[n];
        }

        if(dp[n]!=-1) return dp[n];

        dp[n] = solve(dp, n-1) + solve(dp, n-2);

        return dp[n];
    }
    
    int climbStairs(int n) {
        if(n <= 2) return n;

        vector<int> dp(n+1, -1);
        return solve(dp, n);
    }
};