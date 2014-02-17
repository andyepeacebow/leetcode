class Solution {
public:

	// memory complexity = O(n)
	// time complexity = O(n)
	int removeElement_mem_effic(int A[], int n, int elem) {
        
		int *B = new int[n];
		int res = n;
		int b_idx = 0;
		for (int i = 0; i < n; i ++) {
			if (A[i] != elem) {
				B[b_idx] = A[i];
				b_idx ++;
			}
		}
		memcpy(A, B, n * sizeof (int));
        
		return b_idx;
    }

	// memory complexity = O(1)
	// time complexity = O(nlogn)
    int removeElement(int A[], int n, int elem) {
        
        int res;
        sort(A, A + n);
        int lo = lower_bound(A, A + n, elem) - A;
        if (lo >= n || A[lo] != elem) return n;
        
        // A[] contains elem, and A[lo] == elem
        int hi = upper_bound(A, A + n, elem) - A;
        if (hi >= n) {
            res = lo;
        } else {
            int offset = hi - lo;
            for (int i = hi; i < n; i ++) {
                A[i - offset] = A[i];
            }
            res = n - offset;
        }
        
        return res;
    }
};
