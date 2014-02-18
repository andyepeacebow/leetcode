class Solution {
public:
    int singleNumber(int A[], int n) {
        int bit_cnt[32] = {};
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < 32; j ++) {
                if ( (A[i] >> j) & 1 ) {
                    bit_cnt[j] ++;
                }
            }
        }
        
        int res = 0;
        for (int i = 0; i < 32; i ++) {
            if (bit_cnt[i] % 3 == 1) {
                res += 1 << i;
            }
        }
        
        return res;
    }
};