class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n = weights.size();
        priority_queue<int> maxHeap;
        priority_queue<int, vector<int>, greater<>> minHeap;
        for(int i = 0;i<n-1;i++){
            maxHeap.push(weights[i] + weights[i+1]);
            minHeap.push(weights[i] + weights[i+1]);
        }
        long long maxsum = 0, minsum = 0;
        for(int i = 0;i<k-1;i++){
            maxsum += 1LL * maxHeap.top();
            maxHeap.pop();
            minsum += 1LL * minHeap.top();
            minHeap.pop();
        }
        return maxsum - minsum;
    }
};