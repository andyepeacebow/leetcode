class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        int i1 = m - 1, i2 = n - 1;
        while (i1 >= 0 && i2 >= 0) {
            if (A[i1] >= B[i2]) {
                A[i1 + i2 + 1] = A[i1];
                i1 --;
            } else {
                A[i1 + i2 + 1] = B[i2];
                i2 --;
            }
        }
        
        while (i2 >= 0) {
            A[i2] = B[i2];
            i2 --;
        }
    }
};