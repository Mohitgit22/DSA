class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
          
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        queue<pair<int, int>> que;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(i == 0 || i == m-1 || j == 0 || j == n-1){
                if(grid[i][j] == 1)
                  que.push({i, j});
                  vis[i][j] = true;
                }

                if(grid[i][j] == 0)
                vis[i][j] = true;
            }
        }

        int dx[4] = {0,0, 1, -1};
        int dy[4] = {-1, 1, 0, 0};
        
        while(!que.empty()){
           int x = que.front().first;
           int y = que.front().second;
           que.pop();
        for(int i = 0; i < 4; i++){
           int newx = x + dx[i];
           int newy = y + dy[i];

           if(newx >= 0 and newy >= 0 and newx < m and newy < n and grid[newx][newy] == 1 and vis[newx][newy] == false){
            vis[newx][newy] = true;
            que.push({newx, newy});
           }
          }
        }

        int cnt= 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(vis[i][j] == false)
                cnt++;
            }
        }
        return cnt;
    }
};