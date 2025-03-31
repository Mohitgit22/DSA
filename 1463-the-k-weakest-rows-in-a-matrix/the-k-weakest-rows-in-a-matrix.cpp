#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
    //      vector<pair<int, int>> soldierCount;  // Stores (number of soldiers, row index)

    // for (int i = 0; i < mat.size(); i++) {
    //     int soldierCounts = count(mat[i].begin(), mat[i].end(), 1);  // Count soldiers (1s)
    //     soldierCount.push_back({soldierCounts, i});
    // }


    vector<pair<int, int>> soldiercnt;

    for(int i = 0; i < mat.size(); i++) {
        int cnt = count(mat[i].begin(), mat[i].end(), 1);
        soldiercnt.push_back({cnt, i});
    }
    sort(soldiercnt.begin(), soldiercnt.end());

    vector<int> result;
    for (int i = 0; i < k; i++) {
        result.push_back(soldiercnt[i].second);
    }
    return result;
    }
};