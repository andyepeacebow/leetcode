class Solution {
public:
    void sortColors(int A[], int n) {
        int i0, i1, i2;
        i0 = i1 = i2 = 0;
        for (int i = 0; i < n; i ++) {
            if (A[i] == 0) {
                A[i2] = 2, i2 ++;
                A[i1] = 1, i1 ++;
                A[i0] = 0, i0 ++;
            } else if (A[i] == 1) {
                A[i2] = 2, i2 ++;
                A[i1] = 1, i1 ++;
            } else {
                A[i2] = 2, i2 ++;
            }
        }
    }
};