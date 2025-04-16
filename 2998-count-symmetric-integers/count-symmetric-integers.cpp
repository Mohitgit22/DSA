class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int cnt = 0;
        for(int i = low; i <= high; i++) {
            string s = to_string(i);
            int len = s.length();
            
            if(len % 2 != 0 ) continue;
            
            int leftsum = 0, rightsum = 0 ;
            for(int j = 0; j < len/2 ; j++) {
                  int leftnum = s[j] - '0';
                  int rightnum = s[len - 1-j] - '0';
                  leftsum += leftnum;
                   rightsum += rightnum;
            }
            if(leftsum == rightsum) cnt++;
        }
        return cnt;
    }
};