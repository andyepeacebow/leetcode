class Solution {
public:
	vector<string> ans;
	vector<int> dp;
	int maxWordLen;

	void addAns(vector<string> &vec) {
		string str;
		for (int i = 0; i < vec.size(); i ++) {
			if (i > 0) {
				str += " ";
			}
			str += vec[i];
		}
		ans.push_back(str);
	}

	bool dfs(int idx, int n, string &s, unordered_set<string> &dict, vector<string> &vec) {
		if (idx >= n) {
			addAns(vec);
			return true;
		}
		if (dp[idx] == 0) return false;

		string word;
		int &ret = dp[idx];
		for (int i = idx; i < min(n, idx + maxWordLen); i ++) {
			word += s[i];
			if (dict.find(word) != dict.end()) {
				vec.push_back(word);
				int once = dfs(i + 1, n, s, dict, vec);
				if (once) ret = true;
				vec.pop_back();
			}
		}
		if (ret != 1) ret = 0;
		return ret;
	}

    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        int len = s.length();
		unordered_set<string>::iterator it;
		maxWordLen = 0;
		for (it = dict.begin(); it != dict.end(); it ++) {
			maxWordLen = max(maxWordLen, static_cast<int>((*it).length()));
		}
		
		dp.resize(len, -1);
		vector<string> vec;
		dfs(0, len, s, dict, vec);
		return ans;
    }
};