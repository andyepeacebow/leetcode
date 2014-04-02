class Solution {
public:
	int search_On(int A[], int n, int target) {
        for (int i = 0; i < n; i ++) {
			if (A[i] == target) {
				return i;
			}
		}

		return -1;
    }

    int search_Ologn(int A[], int n, int target) {
        if (n == 0) return -1;

		int v = A[0];
		int lb = 0, ub = n;
		while (lb + 1 < ub) {
			int md = (lb + ub) >> 1;
			if (A[md] >= v) {
				lb = md;
			} else { // A[md] < v
				ub = md;
			}
		}

		// ub is the first idx that A[idx] < v
		int res;
		if (ub < n) {
			res = lower_bound(A + ub, A + n, target) - A;
			if (res < n && A[res] == target) {
				return res;
			}
		}
		res = lower_bound(A, A + ub, target) - A;
		if (res < n && A[res] == target) {
			return res;
		} else {
			return -1;
		}
    }
};