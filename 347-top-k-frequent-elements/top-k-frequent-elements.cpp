class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;

        for(int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minh;

        for(auto it : mp){
            int num = it.first;
            int freq = it.second;
            minh.push({freq, num});
            if(minh.size() > k)
            minh.pop();
        }

        vector<int> ans;
        while(minh.size()){
            int x = minh.top().second;
            ans.push_back(x);
            minh.pop();
        }
        return ans;
    }
};