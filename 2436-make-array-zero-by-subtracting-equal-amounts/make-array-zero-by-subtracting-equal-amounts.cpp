class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        map<int,int>mp;
        for(auto x:nums)
        mp[x]++;
        
        return mp.find(0)==mp.end()?mp.size():mp.size()-1;
        
    }
};