class Solution {
public:
    int fillCups(vector<int>& amount) {
         
        priority_queue<int> maxh;
        for(int i = 0; i < amount.size(); i++){
            if(amount[i]!=0)
            maxh.push(amount[i]);
        }

        int cnt= 0;
        while(maxh.size() > 1){
            int x = maxh.top();
            maxh.pop();
            int y = maxh.top();
            maxh.pop();
            cnt++;

            x = x-1;
            y = y-1;
            if(x!=0)maxh.push(x);
            if(y!=0) maxh.push(y);
        }

        if(maxh.size() > 0 ){
            int x = maxh.top();
            maxh.pop();
            cnt+=x;
        }
 return cnt;

    }
};