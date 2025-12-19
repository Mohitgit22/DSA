class Solution {
public:
    void dfs(vector<vector<int>>& adj, int u, vector<bool>& vis){
         vis[u] = true;

         for(int &v : adj[u]){
            if(vis[v] == false){
                dfs(adj, v, vis);
            }
         }
    }

    int findCircleNum(vector<vector<int>>& con) {
        int n = con.size();

        vector<vector<int>> adj(n);

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i!=j and con[i][j] == 1){
                    adj[i].push_back(j);
                }
            }
        }


        vector<bool> vis(n, false);
        int cnt= 0;
        for(int i = 0; i < n; i++){
              if(vis[i] == false){
                cnt++;
                dfs(adj, i, vis);
              }
        }
         return cnt;
    }
};