class Solution {
public:
    void sum(string s,  unordered_map<int, int>& mp){
         int len = s.length();
         int sum = 0;
         for(auto it : s){
            sum += it-'0';
         }
        mp[sum]++;
    }

    int countLargestGroup(int n) {
        unordered_map<int, int> mp;
        priority_queue<pair<int, int>> maxh;
        for(int i = 1; i <= n; i++){
            string s = to_string(i);
            sum(s, mp);
        }
       
       for(auto it : mp){
        maxh.push({it.second, it.first});
       }

       int largest = maxh.top().first, cnt= 1;
       maxh.pop();
       while(maxh.empty() == false){
            pair<int, int> p = maxh.top();
            maxh.pop();
            if(largest == p.first) cnt++;
            else break;
        }
        return cnt;
    }
};