// class Solution {
// public:
//     void sum(string s,  unordered_map<int, int>& mp){
//          int len = s.length();
//          int sum = 0;
//          for(auto it : s){
//             sum += it-'0';
//          }
//         mp[sum]++;
//     }

//     int countLargestGroup(int n) {
//         unordered_map<int, int> mp;
//         priority_queue<pair<int, int>> maxh;
//         for(int i = 1; i <= n; i++){
//             string s = to_string(i);
//             sum(s, mp);
//         }
       
//        for(auto it : mp){
//         maxh.push({it.second, it.first});
//        }

//        int largest = maxh.top().first, cnt= 1;
//        maxh.pop();
//        while(maxh.empty() == false){
//             pair<int, int> p = maxh.top();
//             maxh.pop();
//             if(largest == p.first) cnt++;
//             else break;
//         }
//         return cnt;
//     }
// };





class Solution {
    int getsum(int n) {
        int sum = 0;
        while (n != 0) {
            sum += (n % 10);
            n = n / 10;
        }
        return sum;
    }

public:
    int countLargestGroup(int n) {
        vector<int> v;
        map<int,int> mp;
        
        for (int i = 1; i <= n; i++) {
            int val = getsum(i);
            mp[val]++;
        }
        for (auto i : mp) {
            v.push_back(i.second);  
        }
        
        int max_ = 0;
        for (int i = 0; i < v.size(); i++) {
            if (v[i] > max_) {
                max_ = v[i];
            }
        }
        int count = 0;
        for (int i = 0; i < v.size(); i++) {
            if (v[i] == max_) {
                count++;
            }
        }
        
        return count;
    }
};