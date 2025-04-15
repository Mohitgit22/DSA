class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        int n = arr.size()-1;
        stack<pair<int, pair<int, int>>> st;
        for(int i = 0; i <= n; i++) {
            for(int j =  n ; j > i; j--) {

                for(int k = j+1; k <= n; k++){
                    if((abs(arr[i] - arr[j]) <= a) and (abs(arr[j] - arr[k]) <= b) and (abs(arr[i] - arr[k]) <= c))
                    st.push({arr[i], {arr[j], arr[k]}});
                }
            }
        }

        // for(auto it : st){
        //     pair<int, pair<int, int>> p = it;
        //     cout << "p first " << p.first <<endl;
        //     cout<< "p second-first "<< p.second.first <<endl;
        //     cout<< "p second-second " << p.second.second << endl;
        // }
        return st.size();
    }
};