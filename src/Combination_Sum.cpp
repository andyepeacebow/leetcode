class Solution {
public:

	vector<vector<int>> res;
	vector<int> can;
	int tar, n;

	void dfs (int idx, int cur, vector<int> &rec) {
		if (cur > tar) return;

		if (cur == tar) {
			res.push_back(rec);
			return;
		}

		if (idx >= n) return;

		for (int i = 0; ; i ++) {
			int nxt = cur + can[idx] * i;
			if (nxt > tar) break;

			if (i > 0) {
				for (int j = 0; j < i; j ++)
					rec.push_back(can[idx]);
			}
			dfs(idx + 1, nxt, rec);
			if (i > 0) {
				for (int j = 0; j < i; j ++)
					rec.pop_back();
			}
		}
	}

    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        can = candidates;
		sort(can.begin(), can.end());
		n = can.size();
		res.clear();
		if (n == 0) return res;

		tar = target;
		vector<int> rec;
		dfs(0, 0, rec);

		return res;
    }
};