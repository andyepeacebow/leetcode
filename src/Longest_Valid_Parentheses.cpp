class Solution {
public:
	vector<int> dp;
	int len;

    int longestValidParentheses(string s) {
        len = s.length();

		dp.clear();
		dp.resize(len, 0);

		int res = 0;
		for (int i = len - 2; i >= 0; i --) {
			if (s[i] == ')') {
				dp[i] = 0;
			} else {
				int nxt = i + 1 + dp[i + 1];
				if (nxt < len && s[nxt] == ')') {
					dp[i] = dp[i + 1] + 2;
					if (nxt + 1 < len) {
						dp[i] += dp[nxt + 1];
					}
				}
			}
			res = max(res, dp[i]);
		}

		return res;
    }
};