class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int maxsum = INT_MIN;
        int i = 0;
        int n = nums.size();

        int sum = 0;
        while( i < n && i < k){
          sum += nums[i];
          i++;
        }
       
        maxsum = sum;

        for(i =1; i< n-k+1; i++) {
         sum = sum - nums[i-1] + nums[i+k-1];
         maxsum = max(sum, maxsum);
        }

        double ans = double(maxsum)/double(k);
        return ans;
    }
};