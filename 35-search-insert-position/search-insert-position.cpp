class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        //return lower bound index

        int n = nums.size();

        if(target < nums[0])return 0;
        if(target > nums[n-1]) return n;

        return lb(nums, target, n);
    }

    int lb(vector<int>& nums, int t, int n){
        int l = 0, r = n-1;
      
        int ind = -1;
        while(l <= r){
            int mid = l + (r-l)/2;
            if(nums[mid] >= t){
                ind = mid;
                r = mid-1;
            }else
             l = mid+1;
        }
        return ind;
    }
};