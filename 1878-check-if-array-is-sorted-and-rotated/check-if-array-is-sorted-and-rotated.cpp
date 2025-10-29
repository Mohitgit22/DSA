class Solution {
public:
    bool check(vector<int>& nums) {
        int cnt = 0;
        int n = nums.size();
         
        int pvt = 0;

        for(int i = 0; i < n-1; i++){
            if(nums[i] > nums[i+1]){
            cnt++;
            pvt = i+1;
            }

            if(cnt > 1)
            return false;
        }

        vector<int> arr;
        for(int i = pvt; i < n; i++)arr.push_back(nums[i]);
        for(int i = 0; i < pvt; i++)arr.push_back(nums[i]);

        for(int i = 0; i < n-1; i++){
            if(arr[i] > arr[i+1]) return false;
        }
        return true;
    }
};