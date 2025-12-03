class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
     bool flag = false;
        for(int i = n-1; i > 0; i--){
            if(nums[i] > nums[i-1]){
                int idx = i-1;
                flag = true;
                for(int j = n-1; j > idx; j--){
                    if(nums[j] > nums[idx]){
                        swap(nums[j], nums[idx]);
                        break;
                    }
                }
                
                reverse(nums.begin() + idx+1, nums.end());
            }
            if (flag) break;
        }

        if(flag == false) reverse(nums.begin(), nums.end());
    }
};