class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
       
       vector<int> v(26,0);
       vector<int> v2(26,0);

       for(auto c:p){
         int idx=c-'a';
         v[idx]++;
       }

        int j = 0;
        vector<int> ans;
        int plen = p.length();
        string temp = "", curr = "";
        for(int i = 0; i < s.length(); i++) {
            if(i>=plen){
                v2[s[j]-'a']--;
                j++;
            }
            v2[s[i]-'a']++;
            if(v==v2){
                ans.push_back(i-plen+1);
            }
        }
        return ans;
    }
};