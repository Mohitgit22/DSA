class Solution {
public:
    int find(vector<int>& nums){
        int n = nums.size();

        int l = 0, r = n-1;

        while(l <= r){
           int mid = l + (r-l)/2;

           if(mid == 0 and nums[mid] > nums[mid+1]) return mid;

           if(mid == n-1 and nums[mid] > nums[mid-1]) return mid;

           if(mid-1 >= 0 and mid +1< n and nums[mid] > nums[mid-1] and nums[mid] > nums[mid+1]) return mid;

           if (nums[mid] < nums[mid + 1])
            l = mid + 1;
           else
            r = mid;
        }
        return -1;
    }
    int findPeakElement(vector<int>& nums) {
        if(nums.size() == 1) return 0;
        return find(nums);
    }
};