class Solution {
public:
	unordered_set<string> dict;
	unordered_map<string, int> word2cnt, cur2cnt;
	vector<int> ans;
	int wlen, slen, wcnt, len;
	string str;

	void calc(int idx) {
		int cnt = 0;
		cur2cnt.clear();
		int s = idx, t = idx;
		int target = word2cnt.size();
		while (s < slen) {
			string word = str.substr(s, wlen);
			
			while (t < slen && cnt < target) {
				word = str.substr(t, wlen);
				if (dict.find(word) != dict.end()) {
					cur2cnt[word] ++;
					if (cur2cnt[word] == word2cnt[word]) {
						cnt ++;
					}
				}
				t += wlen;
			}

			bool ok = cnt == target && t - s == len;
			if (cnt == target && ok) {
				ans.push_back(s);
			}
			word = str.substr(s, wlen);
			if (dict.find(word) != dict.end()) {
				cur2cnt[word] --;
				if (cur2cnt[word] == word2cnt[word] - 1) {
					cnt --;
				}
			}
			s += wlen;
		}
	}

    vector<int> findSubstring(string S, vector<string> &L) {
		wcnt = L.size();
		if (wcnt == 0) return ans;
		wlen = L[0].length();
		slen = S.length();
		str = S;

		len = 0;
        for (int i = 0; i < L.size(); i ++) {
			dict.insert(L[i]);
			word2cnt[L[i]] ++;
			len += L[i].length();
		}
		for (int i = 0; i < wlen; i ++) {
			calc(i);
		}
		return ans;
    }
};