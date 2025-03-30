class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> mp;
        vector<int> ans;

        for(int i = 0; i < s.length(); i++){
            mp[s[i]] = i;
        }


     
       for(int i = 0; i < s.length(); i++){
          int till = mp[s[i]];
          
          int j = i;
          while(j <= till ){
            if(mp[s[j]] > till){
                till = mp[s[j]];
            }
            j++;
            
          }
           int len = j-i;
            ans.push_back(len);
            i=j-1;

       }
        
        // for(auto it : ans){
        //     cout<<it<< " hi";
        // }
        return ans;
    }
};