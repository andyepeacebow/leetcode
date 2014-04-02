class Solution {
public:
	int ***dp;
	string sa, sb;

	int dfs(int len, int i1, int i2) {
		int &ret = dp[len][i1][i2];
		if (ret != -1) {
			return ret;
		}
		if (len == 1) {
			ret = sa[i1] == sb[i2];
			return ret;
		}

		for (int i = 1; i < len; i ++) {
			ret = dfs(i, i1, i2) && dfs(len - i, i1 + i, i2 + i);
			if (ret) return ret;

			ret = dfs(i, i1, i2 + len - i) && dfs(len - i, i1 + i, i2);
			if (ret) return ret;
		}

		return ret;
	}

    bool isScramble(string s1, string s2) {
        if (s1.length() != s2.length()) return false;
		int len = s1.length();
		sa = s1, sb = s2;

		
		dp = new int**[len + 1];
		for(int x = 0; x < len + 1; ++x) {
			dp[x] = new int*[len + 1];
			for(int y = 0; y < len + 1; ++y) {
				dp[x][y] = new int[len + 1];
				for(int z = 0; z < len + 1; ++z) { // initialize the values to whatever you want the default to be
					dp[x][y][z] = -1;
				}
			}
		}


		int res = dfs(len, 0, 0);

		return res;
    }
};