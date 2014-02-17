class Solution {
public:
    int maxSubArray(int A[], int n) {
        vector<int> psum(n + 1, 0);
        int small = 0;
        int res = A[0];
        for (int i = 1; i <= n; i ++) {
            psum[i] = psum[i - 1] + A[i - 1];
            int once = psum[i] - small;
            res = max(res, once);
            small = min(small, psum[i]);
        }
        
        return res;
    }
};