class Solution {
public:
    int majorityElement(vector<int>& nums) {
       int n = nums.size();
       int maj_el = nums[0];
       int cnt = 1;

       for(int i = 1; i < n; i++){
              if(cnt == 0){
                  maj_el = nums[i];
                  cnt = 1;
                  continue;
                }
             else if(nums[i] == maj_el){
            cnt++;
             }
            else{
                cnt--;
            }
       }
       return maj_el;
    }
};