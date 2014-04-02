class Solution {
public:
    int firstMissingPositive(int A[], int n) {
		for (int i = 0; i < n; i ++) {
			if (A[i] == i + 1 || A[i] < 1 || A[i] > n) continue;

			int idx = i;
			while (A[idx] != idx + 1) {
				int val = A[idx];
				if (A[val - 1] == val) break;

				swap(A[idx], A[val - 1]);
				if (A[i] == i + 1 || A[i] < 1 || A[i] > n) {
					break;
				}
			}
		}

		int res = n + 1;
		for (int i = 0; i < n; i ++) {
			if (A[i] != i + 1) {
				res = i + 1;
				break;
			}
		}

		return res;
    }
};