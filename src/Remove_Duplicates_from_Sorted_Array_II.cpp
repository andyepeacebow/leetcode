class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if (n <= 2) return n;
        
        int idx = 0, i = 0;
        while (i < n) {
            int val = A[i];
            int nxt = upper_bound(A, A + n, val) - A;
            int cnt = nxt - i;
            
            A[idx] = val, idx ++;
            if (cnt >= 2) {
                A[idx] = val, idx ++;
            }
            
            i = nxt;
        }
        
        return idx;
    }
};