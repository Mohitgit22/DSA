class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
         unordered_map<string, int> mp;

        // Count word frequencies
        for(auto& word : words){
            mp[word]++;
        }
       
        // Custom comparator for min heap:
        // The word with lower frequency or (if frequencies are same) 
        // lexicographically larger word should be at the top
        auto comparator = [](const pair<int, string>& a, const pair<int, string>& b) {
            if (a.first != b.first) {
                return a.first > b.first; // Lower frequency at top
            }
            return a.second < b.second; // For same frequency, lexicographically smaller at bottom
        };
        
        priority_queue<pair<int, string>, vector<pair<int, string>>, decltype(comparator)> minh(comparator);

        // Add words to min-heap, keeping only k elements
        for(auto it : mp){
            string s = it.first;
            int freq = it.second;
            minh.push({freq, s});

            if(minh.size() > k)
                minh.pop();  // Remove word with lowest frequency or lexicographically larger if tied
        }
     
        // Extract result (will be in reverse order)
        vector<string> ans;
        while(!minh.empty()){
           ans.push_back(minh.top().second);
           minh.pop();
           }
        reverse(ans.begin(), ans.end());
        
        return ans;}
};