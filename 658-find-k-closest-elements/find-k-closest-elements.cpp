  typedef pair<int, int> P;

class Solution {
public:
    
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
       
        priority_queue<P> maxh;
        for(int i = 0; i < arr.size(); i++){
            maxh.push({abs(arr[i] - x), i});

          if(maxh.size() > k) maxh.pop();
        }

        vector<int> ans;
        while(maxh.size()){
            auto it = maxh.top();
            maxh.pop();

            int ele = arr[it.second];
            ans.push_back(ele);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};