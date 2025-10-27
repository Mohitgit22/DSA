class Solution {
public:
    void NSR(vector<int>& arr, vector<int>& nsr){
        stack<int> st;
        int n = arr.size();

        for(int i = n-1; i >= 0; i--){
            while(!st.empty() and arr[st.top()] >= arr[i])
            st.pop();

            int ind = st.empty() ? n : st.top();
            nsr.push_back(ind);
            st.push(i);
        }
        reverse(nsr.begin(), nsr.end());
    }

      void NSL(vector<int>& arr, vector<int>& nsl){
        stack<int> st;
        int n = arr.size();

        for(int i = 0; i < n; i++){
            while(!st.empty() and arr[st.top()] > arr[i])
            st.pop();

            int ind = st.empty() ? -1 : st.top();
            nsl.push_back(ind);
            st.push(i);
        }
        // reverse(nsr.begin(), nsr.end());
    }

    int sumSubarrayMins(vector<int>& arr) {
        
        vector<int> nsr, nsl;
        NSR(arr, nsr);
        NSL(arr, nsl);
         const int MOD = 1e9 + 7;

       int n = arr.size();
       vector<int>left(n), right(n);
       for(int i = 0; i < n; i++){
             left[i] = abs(i - nsl[i]);
             right[i] = abs(nsr[i] - i);
       }

       long long sum = 0;
        for(int i = 0; i < n; i++){
            sum = (sum + (1LL * arr[i] * left[i] % MOD * right[i] % MOD) % MOD) % MOD;
        }

        return (int)sum;

    }
};