class Solution {
public:
	vector<vector<int>> dp;
	int m, n;

    int maximalRectangle(vector<vector<char> > &matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) return 0;

		m = matrix.size();
		n = matrix[0].size();

		vector<int> tmp(n + 1, 0);
		for (int i = 0; i <= n; i ++) {
			dp.push_back(tmp);
		}

		int res = 0;
		for (int i = 1; i <= m; i ++) {
			for (int c1 = 1; c1 <= n; c1 ++) {
				bool ok = true;
				for (int c2 = c1; c2 <= n; c2 ++) {
					if (matrix[i - 1][c2 - 1] == '0') {
						ok = false;
					}

					if (!ok) {
						dp[c1][c2] = 0;
					} else {
						dp[c1][c2] ++;
						int once = dp[c1][c2] * (c2 - c1 + 1);
						res = max(res, once);
					}
				}
			}
		}

		return res;
    }
};