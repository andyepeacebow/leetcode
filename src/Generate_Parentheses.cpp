class Solution {
public:
	vector<string> ans;

	void dfs(int idx, int bal, int n, string &once) {
		int rem = n - idx;
		if (bal < 0 || abs(bal) > rem) return;

		if (idx >= n) {
			ans.push_back(once);
			return;
		}

		once += "(";
		dfs(idx + 1, bal + 1, n, once);
		once.pop_back();

		once += ")";
		dfs(idx + 1, bal - 1, n, once);
		once.pop_back();
	}

    vector<string> generateParenthesis(int n) {
		if (!n) return ans;

		string once;
		dfs(0, 0, 2 * n, once);

		return ans;
    }
};