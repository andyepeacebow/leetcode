class Solution {
public:
	int len;
	vector<int> dp;
	string str;

	int calc(int idx) {
		if (idx >= len) {
			if (idx == len) {
				return 1;
			} else {
				return 0;
			}
		}
		int &ret = dp[idx];

		if (ret != -1) return ret;

		if (str[idx] == '0') {
			ret = 0;
		} else {
			int num;
			if (idx + 1 >= len) {
				num = str[idx] - '0';
			} else {
				num = (str[idx] - '0') * 10 + str[idx + 1] - '0';
			}
			if (num <= 26) {
				ret = calc(idx + 1) + calc(idx + 2);
			} else {
				ret = calc(idx + 1);
			}
		}
		return ret;
	}

    int numDecodings(string s) {
        len = s.length();
		if (!len) return 0;

		str = s;
		dp.resize(len, -1);

		int res = calc(0);
		return res;
    }
};