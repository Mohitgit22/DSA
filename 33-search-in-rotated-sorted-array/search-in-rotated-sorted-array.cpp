class Solution {
public:
   int findpvt(vector<int> & nums){
    int n = nums.size();

    for(int i = 0; i < n-1; i++){
        if(nums[i] > nums[i+1])
        return i+1;
    }
    return 0;
   }
   
    int bs(vector<int>& nums, int l, int r, int t){
        while(l <= r){
            int mid = l + (r-l)/2;
            if(nums[mid] == t) return mid;
            else if(nums[mid] > t) r= mid-1;
            else
            l = mid + 1;
        }
        return -1;
    }
    int search(vector<int>& nums, int t) {
        int pvt = findpvt(nums);

        int x = bs(nums, 0, pvt-1, t);
        int y = bs(nums, pvt, nums.size()-1, t);

        if(x != -1) return x;
        if(y != -1) return y;

        return -1;
    }
};