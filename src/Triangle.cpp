class Solution {
public:
	static const int MAX = 0x6fffffff;

    int minimumTotal(vector<vector<int> > &triangle) {
        int lev = triangle.size();

		vector<int> dp[2];
		dp[0].resize(lev);
		dp[1].resize(lev);

		int pre = 0, nxt = 1;

		dp[0][0] = triangle[0][0];

		for (int i = 1; i < lev; i ++) {
			for (int j = 0; j <= i; j ++) {
				int le = j - 1 >= 0 ? dp[pre][j - 1] : MAX;
				int ri = j < i ? dp[pre][j] : MAX;
				
				dp[nxt][j] = min(le, ri) + triangle[i][j];
			}

			swap(pre, nxt);
		}

		int res = dp[pre][0];
		for (int i = 0; i < lev; i ++) {
			res = min(res, dp[pre][i]);
		}

		return res;
    }
};