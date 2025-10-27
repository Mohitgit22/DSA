class Solution {
public:
    bool search(vector<int>& row, int t){
        for(int it: row){
            if(it == t) return true;
        }
        return false;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
       
  

        vector<int> row;
        for(int i = 0; i < m; i++){
            row.push_back(matrix[i][0]);
        }

        auto it = upper_bound(row.begin(), row.end(), target);
        int ind = it - row.begin() - 1;
       
       //for [[1]] and target = 0, then we get ind = -1;
        if(ind < 0) return false;

        row = matrix[ind];
        return search(row, target);
    }
};