class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
         int m = grid.size();
         int n = grid[0].size();

        vector<vector<int>> sortedgrid;
        vector<int> arr;
        for(int i = 0; i < m; i++) {
            for(int j = 0 ; j< n; j++) {
                arr.push_back(grid[i][j]);
            }
            sort(arr.begin(), arr.end());
            sortedgrid.push_back(arr);
            arr.clear();
        }

    //  for(auto x : sortedgrid){
    //     for( auto y : x){
    //         cout<<y<<" ";
    //     }
    //     cout<<endl;
    //  }
        priority_queue<int> maxh;
        int ans = 0;
        while(n > 0){
        for(int i = 0; i <m; i++) {
                maxh.push(sortedgrid[i][n-1]);
        }
        ans += maxh.top();
        maxh = priority_queue<int>();
        n--;
        }
        return ans;
    }
};