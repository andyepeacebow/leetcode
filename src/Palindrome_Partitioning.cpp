class Solution {
public:
	vector<vector<int>> dp;
	vector<vector<string>> ans;
	int n;
	string ss;

	bool dfs_set(int s, int t) {
		if (s > t) return false;
		
		int &ret = dp[s][t];
		if (ret != -1) return ret;

		if (s == t) {
			ret = true;
		} else if (s + 1 == t) {
			ret = ss[s] == ss[t];
		} else {
			bool inner = dfs_set(s + 1, t - 1);
			ret = inner && ss[s] == ss[t];
		}
		return ret;
	}

	void dfs_find(int s, int n, vector<string> &once) {
		if (s >= n) {
			ans.push_back(once);
			return;
		}

		for (int i = s; i < n; i ++) {
			if (dp[s][i]) {
				once.push_back(ss.substr(s, i - s + 1));
				dfs_find(i + 1, n, once);
				once.pop_back();
			}
		}
	}

    vector<vector<string>> partition(string s) {
        n = s.length();
		ss = s;
		dp.clear();
		for (int i = 0; i < n; i ++) {
			vector<int> tmp(n, -1);
			dp.push_back(tmp);
		}

		for (int i = 0; i < n; i ++) {
			for (int j = i; j < n; j ++) {
				dfs_set(i, j);
			}
		}
		dfs_set(0, n - 1);

		vector<string> once;
		dfs_find(0, n, once);

		return ans;
    }
};
