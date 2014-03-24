class Solution {
public:
	vector<vector<string>> ans;
	vector<int> dp;

	void dfs(int idx, int n) {
		if (idx >= n) {
			vector<string> once;				
			for (int i = 0; i < n; i ++) {
				string line(n, '.');
				line[dp[i]] = 'Q';
				once.push_back(line);
			}
			
			ans.push_back(once);
			return;
		}

		for (int i = 0; i < n; i ++) { // try every position
			bool ok = true;
			for (int j = 0; j < idx; j ++) {
				if (dp[j] == i || j - dp[j] == idx - i || j + dp[j] == idx + i) {
					ok = false;
					break;
				}
			}

			if (ok) {
				dp[idx] = i;
				dfs(idx + 1, n);
			}
		}
	}

    vector<vector<string> > solveNQueens(int n) {
		ans.clear();
		dp.clear();
		dp.resize(n);
        dfs(0, n);

		return ans;
    }
};