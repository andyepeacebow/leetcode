class Solution {
public:
	vector<vector<int>> dp;
	int n;
	string str;

    int lengthOfLongestSubstring(string s) {
        n = s.size();

		set<char> ss;
		int res = 0;
		for (int i = 0; i < n; i ++) {
			ss.clear();
			for (int j = i; j < n; j ++) {
				char ch = s[j];
				if (ss.find(ch) != ss.end()) {
					break;
				} else {
					ss.insert(ch);
				}
				res = max(res, j - i + 1);
			}
		}

		return res;
    }
};