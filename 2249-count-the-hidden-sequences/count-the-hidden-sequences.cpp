class Solution {
public:
    bool check(vector<int>& differences,int idx, int lower, int upper, vector<int>& customvec){
       int n = differences.size();
       int i = 0;
       
       customvec.push_back(idx);

       while(i < n){
            idx += differences[i];
            customvec.push_back(idx);
            if(idx < lower || idx > upper) {
                customvec.clear();
                return false;
            }
        i++;
       }
       return true;
    }
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        
        vector<int> customvec;
        for(int i = lower;i <= upper; i++){
            if(check(differences, i, lower, upper, customvec))
            break;
        }
        if(customvec.size() == 0) return 0;

        int maxi = *max_element(customvec.begin(), customvec.end());
        int mini = *min_element(customvec.begin(), customvec.end());
        int range = abs(upper-maxi) + abs(lower-mini)+1;
        return range;
    }
};