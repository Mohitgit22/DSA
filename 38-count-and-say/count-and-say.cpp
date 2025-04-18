class Solution {
public:
    string func(string s, int n) {
        string ans = "";
        for(int i = 0; i < n; i++ ){
            char ch = s[i];
            int cnt = 1;
            while(i+1 < n and s[i+1] == ch){
                cnt++;
                i++;
            }
            ans += to_string(cnt) + ch;
        }
        return ans;
    }
    string countAndSay(int n) {
        string s = "1";
        for(int i = 2; i <= n; i++){
           int len = s.length();
           s = func(s, len);
        }
        return s;
    }
};