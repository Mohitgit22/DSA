class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));
        priority_queue<pair<int, int>> each_row;
        priority_queue<int> across_rows;
        
        int cnt = n;
        int ans = 0;
        
       while(cnt>0){
        for(int i = 0; i < m ; i++) {
            for(int j = 0 ; j < n; j++) {
                if(visited[i][j] == false){
                each_row.push({grid[i][j], j});
                }
            }
            across_rows.push(each_row.top().first);
            int jth_index = each_row.top().second;
            visited[i][jth_index] = true;
            each_row = priority_queue<pair<int, int>>(); 
        }
        ans += across_rows.top();
        across_rows = priority_queue<int>();
        cnt--;
    }
    return ans;
    }

};