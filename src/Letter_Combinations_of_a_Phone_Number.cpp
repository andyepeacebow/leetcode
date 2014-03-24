class Solution {
public:
	string dig[10];
	vector<string> ans;

	void init() {
		dig[0] = " ";
		dig[1] = "";
		dig[2] = "abc";
		dig[3] = "def";
		dig[4] = "ghi";
		dig[5] = "jkl";
		dig[6] = "mno";
		dig[7] = "pqrs";
		dig[8] = "tuv";
		dig[9] = "wxyz";
		ans.clear();
	}

	void dfs(int idx, int n, string& digits, string &once) {
		if (idx >= n) {
			ans.push_back(once);
			return;
		}

		int d = digits[idx] - '0';
		if (d == 1) {
			dfs(idx + 1, n, digits, once);
		}
		for (int i = 0; i < dig[d].size(); i ++) {
			once += dig[d][i];
			dfs(idx + 1, n, digits, once);
			once.pop_back();
		}
	}

    vector<string> letterCombinations(string digits) {
        init();

		int n = digits.size();
		string once;
		dfs(0, n, digits, once);

		return ans;
    }
};