class Solution {
public:

	//simple version
	//int searchInsert_sim(int A[], int n, int target) {
	//	int idx = lower_bound(A, A + n, target) - A;
	//	return idx;
	//}
    
    int searchInsert(int A[], int n, int target) {
        if (n == 0) {
            return 0;
        } else if (n == 1) {
            return A[0] >= target ? 0 : 1;
        }
        
        // n >= 2
        int lo = 0, hi = n;
        
        while (lo + 1 < hi) {
            int md = (lo + hi) >> 1;
            if (A[md] < target) {
                lo = md;
            } else {
                hi = md;
            }
        }
        
        if (hi > 0 && A[hi - 1] >= target) {
    		hi --;
    	}
        return hi;
    }
};