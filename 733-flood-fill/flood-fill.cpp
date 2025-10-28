class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();

        if (image[sr][sc] == color)
       return image;


        queue<pair<int, int>> que;
        que.push({sr, sc});

        int c = image[sr][sc];

        image[sr][sc]=color;

        int dx[4] = {0, 0, -1,1 };
        int dy[4] = {-1, 1, 0, 0};
        while(!que.empty()){
            auto front = que.front();
            que.pop();
            int x = front.first;
            int y = front.second;
            
            for(int i = 0; i < 4; i++){
                int newx = x + dx[i];
                int newy = y + dy[i];

                if(newx >= 0 and newy >= 0 and newx < m and newy < n and image[newx][newy] == c){
                    image[newx][newy] = color;
                    que.push({newx, newy});
                }
            }
        }

        return image;
    }
};