class Solution {
public:
    int findpvt(vector<int>& nums){
        int n = nums.size();
        int l = 0, r = n-1;

        while(l < r){
            while(l+1 < n and nums[l] == nums[l+1]) l++;
            while(r-1 > 0 and nums[r] == nums[r-1]) r--;

            int mid = l + (r-l)/2;
            if(nums[mid] > nums[r])
            l = mid + 1;
            else 
            r = mid;
        }
        return l;
    }

    bool search(vector<int>& nums, int target) {
        int pvt = findpvt(nums);
        int n = nums.size();

        cout <<"the pvt is" << pvt;
          
        int find1 = find(nums, 0, pvt-1, target);
        int find2 = find(nums, pvt, n-1, target );
        return (find1 || find2);
    }

     int find(vector<int>& nums, int l, int r, int t){
        
        while(l <= r){
           int mid = l + (r-l)/2;
           if(nums[mid] == t) return true;
           else if(nums[mid] > t) r = mid-1;
           else  l = mid+1;
        }
        return false;
    }
};