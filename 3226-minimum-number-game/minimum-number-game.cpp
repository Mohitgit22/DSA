class Solution {
public:
    vector<int> numberGame(vector<int>& nums) {
        priority_queue<int, vector<int>, greater<int>> pq;
       
        for(int i = 0; i < nums.size(); i++) {
            pq.push(nums[i]);
        }

        int i = 0;
        vector<int> ans;
      
        int x, y;
        while(pq.size() > 0) {
            x = pq.top();
           pq.pop();
           if(i%2 == 1){
            ans.push_back(x);
            ans.push_back(y);
            i++;
            continue;
           }
           y = x;
           i++;
        }
        return ans;
        
    }
};