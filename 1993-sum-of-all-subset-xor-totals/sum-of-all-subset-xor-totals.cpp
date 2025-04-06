class Solution {
public:
    void f(vector<int>& nums, int idx,vector<int>& currsubset,vector<vector<int>>& allsubsets) {
       if(idx == nums.size()){
        allsubsets.push_back(currsubset);
        return ;
       }
       
       //not pick
       f(nums, idx + 1, currsubset, allsubsets);
       //pick
       currsubset.push_back(nums[idx]);
       f(nums, idx + 1, currsubset, allsubsets);
       currsubset.pop_back();
    }

    int subsetXORSum(vector<int>& nums) {
        vector<vector<int>> allsubsets;
        vector<int> currsubset;

        f(nums, 0, currsubset, allsubsets);

         int ans = 0;
        for(auto it : allsubsets){
            int xorOfEl = 0;
            for(auto x : it){
                xorOfEl ^= x;
            }
            ans += xorOfEl;
        }
        return ans;
    }
};