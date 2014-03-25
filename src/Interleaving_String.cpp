class Solution {
public:
	int l1, l2, l3;
	string str1, str2, str3;
	vector<vector<int>> dp;

	bool dfs(int i1, int i2, int i3) {
		if (i3 >= l3) return true;

		int &res = dp[i1][i2], r1 = 0, r2 = 0;
		if (res != -1) {
			return res;
		}

		if (i1 < l1 && str1[i1] == str3[i3]) {
			r1 = dfs(i1 + 1, i2, i3 + 1);
		}
		if (i2 < l2 && str2[i2] == str3[i3]) {
			r2 = dfs(i1, i2 + 1, i3 + 1);
		}
		if (r1 || r2) {
			res = true;
		} else {
			res = false;
		}
		return res;
	}

    bool isInterleave(string s1, string s2, string s3) {
        l3 = s3.length();
		l2 = s2.length();
		l1 = s1.length();
		if (l1 + l2 != l3) return false;

		vector<int> tmp(l2 + 1, -1);
		for (int i = 0; i <= l1; i ++) {
			dp.push_back(tmp);
		}

		str1 = s1, str2 = s2, str3 = s3;
		bool res = dfs(0, 0, 0);
		return res;
    }
};