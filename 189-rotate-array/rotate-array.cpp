class Solution {
public:
    void swapno(vector<int>& nums, int st, int end){
        while(st < end){
            swap(nums[st], nums[end]);
            st++;
            end--;
        }
    }
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
     
        k = k%n;
        // if(n < k) return ;
        int c1 = n-k;

        swapno(nums, 0, c1-1);
        swapno(nums, c1, n-1);
        swapno(nums, 0, n-1);
    }
};