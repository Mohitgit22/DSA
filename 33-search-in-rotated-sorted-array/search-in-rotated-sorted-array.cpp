class Solution {
public:
    int findpvt(vector<int>& nums){
        int n = nums.size();

        int l = 0, r = n-1;
        while(l < r){
            int mid = l + (r-l)/2;

            if(nums[mid] > nums[r]){
                l = mid+1;
            }else{
                r = mid;
            }
        }
        return r;
    }



    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int pvt = findpvt(nums);
          
        cout <<"the pvt is" << pvt;
          
        int find1 = find(nums, 0, pvt-1, target);
        
        if(find1 != -1) return find1;

        int find2 = find(nums, pvt, n-1, target );
        return find2;
    }

    int find(vector<int>& nums, int l, int r, int t){
        
        while(l <= r){
           int mid = l + (r-l)/2;
           if(nums[mid] == t) return mid;
           else if(nums[mid] > t) r = mid-1;
           else  l = mid+1;
        }
        return -1;
    }
};