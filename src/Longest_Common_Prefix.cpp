class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        int n = strs.size();
        if (n == 0) return "";
        
		int minlen = 0x6fffffff;
		for (int i = 0; i < n; i ++) {
			if (strs[i].length() < minlen) {
				minlen = strs[i].length();
			}
		}


		for (int i = 1; i < n; i ++) {
			for (int j = 0; j < minlen; j ++) {
				if (strs[i][j] != strs[i - 1][j]) {
					minlen = j;
				}
			}
		}

		string ans = strs[0].substr(0, minlen);
		return ans;
    }
};