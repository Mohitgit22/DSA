class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> mp;
        for(auto it : answers){
            mp[it]++;
        }

        int ans= 0;
        for(auto it : mp){
            int size = it.first + 1;
            int rabbits = it.second;
            ans += ceil((double)rabbits / size) * size;
        }
        return ans;
    }
};