class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> mp;

        int n = nums.size();
        
        int sum = 0;
        for(int i = 0; i < n; i++){
            int curr = nums[i];

            int left = target - curr;

            if(mp.find(left) != mp.end()){
                return {i, mp[left]};
            }

            mp[curr] = i;
        }
        return {-1,-1};
    }
};