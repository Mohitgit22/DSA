class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        if(stones.size() == 1) return stones[0];

        priority_queue<int> pq;
        for(auto it : stones){
            pq.push(it);
        }

        while(pq.size() >= 2){
            int x = pq.top();
            pq.pop();
            int y = pq.top();
            pq.pop();

            if(x == y) continue;

            int left = abs(x - y);
            pq.push(left);
        }

        if(pq.size() == 0) return 0;

        return pq.top();
    }
};