class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0, j = 0;
        int n = nums.size();
        nums[i] = nums[0];
        while(j < n){
           if(nums[j] == nums[i])
           {
            j++;
            continue;
           }

           i++;
           nums[i] = nums[j];
           j++;
        }

        return i+1;
    }
};