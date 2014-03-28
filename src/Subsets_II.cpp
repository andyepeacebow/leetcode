class Solution {
public:
	vector<vector<int>> ans;
	map<int, int> num2Cnt;

	void dfs(map<int, int>::iterator it, vector<int> &once) {
		if (it == num2Cnt.end()) {
			ans.push_back(once);
			return;
		}

		map<int, int>::iterator nxt = it;
		nxt ++;
		for (int i = 0; i <= it->second; i ++) {
			if (i) {
				once.push_back(it->first);
			}
			dfs(nxt, once);
		}

		while (once.size() > 0 && once[ once.size() - 1 ] == it->first) {
			once.pop_back();
		}
	}

    vector<vector<int> > subsetsWithDup(vector<int> &S) {
		int n = S.size();
		for (int i = 0; i < n; i ++) {
			num2Cnt[ S[i] ] ++;
		}

		vector<int> once;
		dfs(num2Cnt.begin(), once);
		return ans;
    }
};