class Solution {
public:
	vector<vector<int>> ans;
	int n;

	bool next(vector<int> &num) {
		int idx = n - 1;
		while (idx > 0 && num[idx - 1] >= num[idx]) idx --;

		if (idx == 0) {
			return false;
		}

		idx --;

		int idx1 = idx, small = 0x6fffffff;
		for (int i = idx + 1; i < n; i ++) {
			if (num[i] > num[idx] && num[i] < small) {
				small = num[i];
				idx1 = i;
			}
		}

		swap(num[idx], num[idx1]);
		sort(num.begin() + idx + 1, num.end());
		return true;
	}

    vector<vector<int> > permuteUnique(vector<int> &num) {
        ans.clear();
		n = num.size();
		if (n == 0) return ans;

		sort(num.begin(), num.end());
		do {
			ans.push_back(num);
		} while (next(num));

		return ans;
    }
};