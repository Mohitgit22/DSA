class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
    int n = nums.size();
    int sum = 0;
    map<int, int> mp;
    int freq = 0;

    for(int i = 0; i< n; i++){
      sum += nums[i];

      if(sum == k)
      freq++;

      int left = sum - k;
      if(mp.find(left) != mp.end()){
        freq += mp[left];
      }

      mp[sum]++;
    }
    return freq;  
    }
};