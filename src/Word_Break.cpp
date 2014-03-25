class Solution {
public:
	vector<int> dp;
	int len;
	string str;

	bool dfs(int idx, unordered_set<string> &dict) {
		if (idx >= len) {
			return true;
		}

		int &ret = dp[idx];
		if (ret != -1) {
			return ret;
		}

		bool res = false;
		for (int i = 1; i < len - idx + 1; i ++) {
			string sub = str.substr(idx, i);
			if (dict.find(sub) == dict.end()) continue;

			bool once = dfs(idx + i, dict);
			if (once) {
				res = true;
				break;
			}
		}

		ret = res;
		return ret;
	}

    bool wordBreak(string s, unordered_set<string> &dict) {
		len = s.length();
		if (!len) return true;
		
		str = s;
		dp.resize(len + 1, -1);
		bool res = dfs(0, dict);
		return res;
    }
};