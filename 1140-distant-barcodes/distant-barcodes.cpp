class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        priority_queue<pair<int, int>> maxh;
        unordered_map <int, int> mp;
        for(auto it : barcodes) {
            mp[it]++;
        }

        for(auto it : mp) {
            int num = it.first;
            int freq = it.second;
            maxh.push({freq, num});
        }
      
       vector<int> ans;
      
        while(maxh.size()>=2) {
            auto first = maxh.top(); 
            int ele1 = first.second;
            int freq1 = first.first;
            maxh.pop();
            auto second = maxh.top();
            int ele2 = second.second;
            int freq2 = second.first;
            
            maxh.pop();
            ans.push_back(ele1);
            ans.push_back(ele2);
            freq1--;
            freq2--;
            if(freq1!=0) maxh.push({freq1, ele1});
            if(freq2!=0) maxh.push({freq2, ele2});
        }

        if(maxh.size() == 1){
            ans.push_back(maxh.top().second);
            maxh.pop();
        }

        return ans;
    }
};