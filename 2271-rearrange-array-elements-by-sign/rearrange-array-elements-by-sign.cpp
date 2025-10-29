class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> even, odd;

        for(int it : nums){
            if(it >= 0){
                even.push_back(it);
            }else
               odd.push_back(it);
        }


        int n = even.size();
        vector<int> ans;
        for(int i = 0; i < n; i++){
            ans.push_back(even[i]);
            ans.push_back(odd[i]);
        }
        return ans;
    }
};