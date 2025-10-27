class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();

        int ind = find(nums, n, target);

        if(ind == -1) return {-1, -1};

        int lind = ind, rind = ind;

        while(lind > 0 and nums[lind] == nums[lind-1])
        lind--;

         while(rind < n-1 and nums[rind] == nums[rind+1])
        rind++;

        return {lind, rind};
    }


    int find(vector<int>& nums, int n, int t){
        int l = 0, r = n-1;
       
        while(l <= r){
            int mid = l + (r-l)/2;
            if(nums[mid] == t) return mid;
            else if(nums[mid] > t) r = mid-1;
            else
            l = mid + 1;
        }
        return -1;
    }
};