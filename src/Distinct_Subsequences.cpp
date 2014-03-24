class Solution {
public:
	unordered_map<char, vector<int>> pos;
	vector<vector<int>> dp;

	int ls, lt;
	int ans;
	string s, t;

	int dfs(int is, int it) {
		int &ret = dp[is][it];
		if (ret != -1) {
			return ret;
		}
		if (it >= lt) {
			ret = 1;
			return ret;
		}
		if (is >= ls) {
			ret = 0;
			return ret;
		}

		ret = 0;
		char ch = t[it];
		vector<int> &vp = pos[ch];
		int from = lower_bound(vp.begin(), vp.end(), is) - vp.begin();
		for (int i = from; i < vp.size(); i ++) {
			int apos = vp[i];
			int once = dfs(apos + 1, it + 1);
			ret += once;
		}

		return ret;
	}

    int numDistinct(string S, string T) {
        ls = S.length();
		lt = T.length();
		if (ls < lt) return 0;
		if (lt == 0) return 1;

		s = S, t = T;
		vector<int> tmp(lt + 1, -1);
		for (int i = 0; i <= ls; i ++) {
			dp.push_back(tmp);
		}

		for (int i = 0; i < ls; i ++) {
			char ch = S[i];
			pos[ch].push_back(i);
		}

		int ans = dfs(0, 0);
		return ans;
    }
};