class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
       int n = nums.size();

       if(n == 1) return nums[0];

       int l = 0, r = n-1;

       while(l <= r){
        int mid = l + (r-l)/2;

        if(mid%2 == 0 and nums[mid]==nums[mid+1])
         l = mid + 1;
        else if(mid%2 == 0 and nums[mid]!=nums[mid+1])
         r = mid-1;
         else if(mid%2 != 0 and nums[mid]==nums[mid+1])
         r = mid-1;
         else
         l = mid+1;
       }
       return nums[l];
    }
};