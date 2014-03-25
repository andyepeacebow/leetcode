class Solution {
public:
	vector<string> dp;
	unordered_map<string, int> um;
	unordered_map<int, string> um1;

	string calc(string &str) {
		char buf[26] = {};
		int len = str.length();
		for (int i = 0; i < len; i ++) {
			int cidx = str[i] - 'a';
			buf[cidx] ++;
		}
		string ret(buf, buf + 26);
		return ret;
	}

    vector<string> anagrams(vector<string> &strs) {
        int n = strs.size();
		um.clear();
		for (int i = 0; i < n; i ++) {
			string hash = calc(strs[i]);
			um[hash] ++;
			um1[i] = hash;
		}

		vector<string> ans;

		for (int i = 0; i < n; i ++) {
			string &hash = um1[i];
			int cnt = um[hash];
			if (cnt > 1) {
				ans.push_back(strs[i]);
			}
		}
		return ans;
    }
};