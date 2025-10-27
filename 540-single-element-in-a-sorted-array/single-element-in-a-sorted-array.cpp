class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int xori = 0;

        for(int it : nums){
            xori ^= it;
        }

        return xori;
    }
};