class Solution {
public:
    bool isValid(vector<int>&piles, int mid, int h){
       long long cnt = 0;

         for (int it : piles) {
            cnt += (it + mid - 1) / mid;  // integer ceiling division
        }

         return cnt <= h;
    }

    int bs(vector<int>&piles, int l, int r, int h){
        int res = INT_MAX;
        while(l <= r){
            int mid = l + (r-l)/2;

            if(isValid(piles, mid, h)){
                res = min(res, mid);
                r = mid-1;
            }else
                l = mid + 1;
        }
        return res;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = *max_element(piles.begin(), piles.end());

        return bs(piles, l, r, h);
    }
};