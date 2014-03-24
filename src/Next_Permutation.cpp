class Solution {
public:
    void nextPermutation(vector<int> &num) {
		int n = num.size();
		if (n == 0) return;
		
		int idx = n - 1;
		while (idx > 0 && num[idx - 1] >= num[idx]) {
			idx --;
		}

		if (idx == 0) {
			sort(num.begin(), num.end());
			return;
		}
		// digits to the right of num[idx] are in descending order

		idx --;
		int idx1, small = 0x6fffffff;
		for (int j = idx + 1; j < n; j ++) {
			if (num[j] > num[idx] && num[j] <= small) {
				small = num[j];
				idx1 = j;
			}
		}
		swap(num[idx1], num[idx]);

		sort(num.begin() + idx + 1, num.end());
    }
};