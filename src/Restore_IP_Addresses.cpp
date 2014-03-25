class Solution {
public:
	int len;
	vector<string> ans;
	string str;

	void dfs(int id, int idx, vector<int> &once) {
		if (id >= 4 && idx == len) {
			string res;
			for (int i = 0; i < 4; i ++) {
				char buf[10];
				sprintf(buf, "%d", once[i]);
				res += string(buf);
				if (i < 3) {
					res += ".";
				}
			}
			ans.push_back(res);
			return;
		}

		int rem = len - idx;
		if (rem > (4 - id) * 3) return;

		for (int i = 1; i <= 3; i ++) {
			if (idx + i > len) return;

			string sub = str.substr(idx, i);
			int v;
			sscanf(sub.c_str(), "%d", &v);
			if (str[idx] == '0' && i > 1) continue; // no leading 0s

			if (v > 255) break;
			once.push_back(v);
			dfs(id + 1, idx + i, once);
			once.pop_back();
		}
	}

    vector<string> restoreIpAddresses(string s) {
		len = s.length();
        if (len < 4 || len > 3 * 4) return ans;

		str = s;
		vector<int> once;
		dfs(0, 0, once);
		return ans;
    }
};