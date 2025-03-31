class Solution {
public:
    int fillCups(vector<int>& amount) {
        sort(amount.begin(),amount.end());
        int ans=amount[2];
        ans+=max(0,((amount[0]+amount[1]-amount[2]+1)/2));
        return ans;
        
    }
};