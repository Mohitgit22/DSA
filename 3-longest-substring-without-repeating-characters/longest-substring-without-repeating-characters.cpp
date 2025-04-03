class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length() <= 1)
        return s.length();

        int len = 0;
        unordered_map<char, int> mp;
        int j = 0;
        int ans = INT_MIN;

        for(int i = 0; i < s.length(); i++) {
            if(mp.find(s[i]) != mp.end()){
                ans = max(ans, len);
                // int x = mp.size();
                while(mp.find(s[i])!= mp.end() and j<= i){
                    mp[s[j]]--;
                     if (mp[s[j]] == 0) mp.erase(s[j]);
                    len--;
                    j++;
                }
            }
            mp[s[i]]++;
            len++;
        }
        ans = max(ans, len);
        return ans;

    }
};