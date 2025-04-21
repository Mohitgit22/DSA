class Solution {
public:
    int maxi = INT_MIN;
    int mini = INT_MAX;

    bool check(vector<int>& differences,int idx, int lower, int upper){
       int n = differences.size();
       int i = 0;
       
       maxi = idx, mini = idx;
    //    customvec.push_back(idx);

       while(i < n){
            idx += differences[i];
            // customvec.push_back(idx);
            maxi = max(maxi, idx);
            mini = min(mini, idx);
            if(idx < lower || idx > upper) {
                // customvec.clear();
                return false;
            }
        i++;
       }
       return true;
    }
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        
        // vector<int> customvec;
        bool flag = false;
        for(int i = lower;i <= upper; i++){
            if(check(differences, i, lower, upper)){
                flag = true;
            break;
            }
        }
        if(!flag) return 0;
        
        // int maxi = *max_element(customvec.begin(), customvec.end());
        // int mini = *min_element(customvec.begin(), customvec.end());
        int range = abs(upper-maxi) + abs(lower-mini)+1;
        return range;
    }
};