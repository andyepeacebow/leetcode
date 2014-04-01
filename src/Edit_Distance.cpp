class Solution {
public:
	vector<vector<int>> dp;
	int len1, len2;

    int minDistance(string word1, string word2) {
		len1 = word1.size();
		len2 = word2.size();
		vector<int> tmp(len2 + 1, 0);
		for (int i = 0; i <= len1; i ++) dp.push_back(tmp);

		for (int i = 0; i <= len1; i ++) {
			dp[i][0] = i;
		}
		for (int i = 0; i <= len2; i ++) {
			dp[0][i] = i;
		}

		for (int i = 1; i <= len1; i ++) {
			for (int j = 1; j <= len2; j ++) {
				if (word1[i - 1] == word2[j - 1]) {
					dp[i][j] = dp[i - 1][j - 1];
				} else {
					dp[i][j] = min( dp[i - 1][j] + 1, min( dp[i][j - 1] + 1, dp[i - 1][j - 1] + 1) );
				}
			}
		}

		int res = dp[len1][len2];
		return res;
    }
};