class Solution {
public:
	vector<vector<int>> dp1;
	vector<int> dp2;
	string str;
	int len;

	int calc1(int x, int y) {
		if (x > y) return 0;
		int &ret = dp1[x][y];
		if (ret != -1) return ret;
		if (x == y) {
			ret = 1;
		} else if (x + 1 == y) {
			ret = str[x] == str[y];
		} else {
			if (str[x] != str[y]) {
				ret = 0;
			} else {
				ret = calc1(x + 1, y - 1);
			}
		}

		return ret;
	}

	int calc2(int x) {
		if (calc1(0, x)) return 0;

		int &ret = dp2[x];
		if (ret != -1) return ret;

		ret = std::numeric_limits<int>::max();
		for (int i = 1; i <= x; i ++) {
			if (calc1(i, x) == false) continue;

			int once = calc2(i - 1) + 1;
			ret = min(once, ret);
		}
		return ret;
	}

    int minCut(string s) {
        len = s.length();
		if (len <= 1) return 0;
		str = s;
		vector<int> tmp(len + 1, -1);
		for (int i = 0; i < len; i ++) {
			dp1.push_back(tmp);
		}
		dp2.resize(len + 1, -1);

		for (int i = 0; i < len; i ++) {
			for (int j = i; j < len; j ++) {
				calc1(i, j);
			}
		}

		int res = calc2(len - 1);
		return res;
    }
};