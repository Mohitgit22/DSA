class Solution {
public:
    void f(vector<int>& nums, int idx,int currxor, int& ans) {
       if(idx == nums.size()){
        ans += currxor;
        return ;
       }
       //not pick
       f(nums, idx + 1, currxor, ans);
       //pick
       f(nums, idx + 1, currxor ^ nums[idx], ans);
    }

    int subsetXORSum(vector<int>& nums) {
        vector<int> currsubset;
        int currxor = 0;
        int ans = 0;

        f(nums, 0, currxor, ans);

        return ans;
    }
};