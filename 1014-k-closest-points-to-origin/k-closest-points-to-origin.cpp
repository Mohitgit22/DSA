class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, pair<int, int>>> maxh;

        for(auto it : points){
            int x = it[0];
            int y = it[1];
            int sq = pow(x, 2) + pow(y, 2);
            maxh.push({sq, {x, y}});

            if(maxh.size() > k)
            maxh.pop();
        }

        vector<vector<int>>  ans;
        while(maxh.size() > 0) {
            auto it = maxh.top();
            maxh.pop();
            int x_coord = it.second.first;
            int y_coord = it.second.second;
            ans.push_back({x_coord, y_coord});
        }
        return ans;
    }
};