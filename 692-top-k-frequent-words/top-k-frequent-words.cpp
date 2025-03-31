class Solution {
public:
   typedef pair<int, string> P;

    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> wordCount;
        for (const auto& word : words) {
            wordCount[word]++;
        }
        
        // Create a vector of pairs (word, frequency)
        vector<pair<string, int>> freqPairs;
        for (const auto& entry : wordCount) {
            freqPairs.push_back(entry);
        }
        

        auto comparator = [](const pair<string, int>& a, const pair<string, int>& b) {
            if (a.second != b.second) {
                return a.second > b.second; // Higher frequency first
            }
            return a.first < b.first; // Lexicographically smaller first
        };
        
        // Sort using the custom comparator
        sort(freqPairs.begin(), freqPairs.end(), comparator);
        
        // Extract the top k words
        vector<string> result;
        for (int i = 0; i < k && i < freqPairs.size(); i++) {
            result.push_back(freqPairs[i].first);
        }
        
        return result;
    }
};