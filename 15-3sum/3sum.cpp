class Solution {
public:
    void twosum(set<vector<int>>& st, vector<int>& nums, int t, int idx){
        int left = idx+1;
        int n = nums.size();
        int right = n-1;
        while( left < right){
             int sum = nums[left] + nums[right];
            if(sum == t){
            st.insert({nums[idx], nums[left], nums[right]});
            while(left < right and nums[left] == nums[left+1])
            left++;

             while(left < right and nums[right] == nums[right-1])
            right--;
            }

           if(sum < t)
           left++;
           else
           right--;
        }

    }

    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        set<vector<int>> st;
        for(int i = 0; i< n; i++){
            int target = - nums[i];
             twosum(st, nums, target, i);
        }

        vector<vector<int>> ans;
       for (const vector<int>& vec : st) {
       ans.push_back(vec);
       }
        return ans;
    }

};