class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

         vector<vector<int>> ans(m, vector<int>(n, 0));
         vector<vector<bool>> vis(m, vector<bool>(n, false));
         queue<pair<int,pair<int,  int>>> que;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(mat[i][j] == 0){
                    que.push({0,{i, j}});
                    vis[i][j] = true;
                }
            }
        }

       int dx[4] = {0,0,-1,1};
       int dy[4] = {-1,1, 0, 0};

        while(!que.empty()){
            
            int t = que.front().first;
            int x = que.front().second.first;
            int y = que.front().second.second;

            que.pop();

            for(int i = 0; i < 4; i++){
                int newx = x + dx[i];
                int newy = y + dy[i];
               
                if(newx >= 0 and newy >= 0 and newx < m and newy < n and mat[newx][newy] == 1 and vis[newx][newy] == false){
                    ans[newx][newy] = t + 1;
                    vis[newx][newy] = true;
                    que.push({t+1, {newx, newy}});
                }
            }
        }
        return ans;
    }
};