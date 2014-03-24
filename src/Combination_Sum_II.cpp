class Solution {
public:
	vector<vector<int>> ans;
	vector<int> vec;
	map<int, int> numCnt;
	int n, m;

	void dfs(map<int, int>::iterator it, int rem, vector<int> &once) {
		if (rem == 0) {
			ans.push_back(once);
			return;
		}
		if (it == numCnt.end() || rem < 0) return;
		
		int val = it->first, cnt = it->second;
		map<int, int>::iterator nxt_it = it;
		nxt_it ++;
		for (int i = 0; i <= cnt; i ++) {
			int sum = val * i;
			if (sum > rem) break;
			
			if (i > 0) {
				once.push_back(val);
			}
			dfs(nxt_it, rem - sum, once);
		}
		while (once.size() > 0 && once[once.size() - 1] == val) {
			once.pop_back();
		}
	}

    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
		n = num.size();
		if (n == 0) return ans;
		
		sort(num.begin(), num.end());
		for (int i = 0; i < n; i ++) {
			numCnt[ num[i] ] ++;
		}
		
		map<int, int, less<int>>::iterator it = numCnt.begin();
		for (it = numCnt.begin(); it != numCnt.end(); it ++) {
			vec.push_back(it->first);
		}
		m = vec.size();
		
		vector<int> once;
		it = numCnt.begin();
		dfs(it, target, once);
		return ans;
    }
};