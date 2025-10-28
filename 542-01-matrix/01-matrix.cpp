class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        queue<pair<int, pair<int, int>>> que;
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        vector<vector<int>> ans(m, vector<int>(n, 0));

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(mat[i][j] == 0){
                   que.push({0,{i, j}});
                   vis[i][j] = true;
                   ans[i][j] = 0;
                }
            }
        }

        int dx[4] = {0, 0, -1, 1};
        int dy[4] = {-1, 1, 0, 0};

        while(!que.empty()){
            auto f = que.front();
            que.pop();
            int d = f.first;
            int x = f.second.first;
            int y = f.second.second;

            for(int i = 0; i < 4; i++){
                int newx = x + dx[i];
                int newy = y + dy[i];

                if(newx >= 0 and newy >= 0 and newx < m and newy < n and mat[newx][newy] == 1 and !vis[newx][newy]){
                    vis[newx][newy] = true;
                    ans[newx][newy] = d + 1;
                    que.push({d+1, {newx, newy}});
                }
            }
        }
      return ans;

    }
};