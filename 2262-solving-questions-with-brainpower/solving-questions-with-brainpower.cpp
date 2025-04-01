class Solution {
public:
    long long fn(vector<vector<int>>& questions,int i,long long& ans, int n, vector<long long>& dp ){
        if( i >= n )
        return 0;

        int nextIndex = i + questions[i][1] + 1;
        if (nextIndex >= n) nextIndex = n;  // Prevent out-of-bounds access

        if(dp[i] != -1)
        return dp[i];


        return dp[i]= max((questions[i][0] + fn(questions, nextIndex, ans, n, dp)), fn(questions, i+1, ans, n, dp));  
        
    }

    long long mostPoints(vector<vector<int>>& questions) {
        
    long long ans = 0;
    int n = questions.size();
    int i = 0;
    vector<long long> dp(n, -1);
    return fn(questions,i, ans, n, dp);
    }
};