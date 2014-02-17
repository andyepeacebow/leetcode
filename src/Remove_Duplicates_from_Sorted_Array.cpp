class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if (n <= 1) return n;
        
        
        int len = 0;
        int cur = 0;
        while (cur < n) {
            int val = A[cur];
            A[len] = val, len ++;
            int nxt = upper_bound(A, A + n, val) - A;
            cur = nxt;
        }
        
        
        return len;
    }
};