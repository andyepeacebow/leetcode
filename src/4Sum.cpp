class Solution {
public:
	unordered_map<int, vector<pair<int, int>>> sum2pair;
	unordered_map<int, int> num2cnt;
	int n;
	vector<vector<int>> ans;

	bool check(int a1, int a2, int a3, int a4) {
		unordered_map<int, int> cnt;
		cnt[a1] ++;
		cnt[a2] ++;
		cnt[a3] ++;
		cnt[a4] ++;

		unordered_map<int, int>::iterator it;
		for (it = cnt.begin(); it != cnt.end(); it ++) {
			if (num2cnt[it->first] < it->second) return false;
		}
		return true;
	}

    vector<vector<int> > fourSum(vector<int> &num, int target) {
        n = num.size();
		if (n < 4) return ans;

		for (int i = 0; i < n; i ++) {
			int v = num[i];
			num2cnt[v] ++;
		}

		unordered_map<int, int>::iterator it1, it2;
		for (it1 = num2cnt.begin(); it1 != num2cnt.end(); it1 ++) {
			for (it2 = it1; it2 != num2cnt.end(); it2 ++) {
				int sum2 = it1->first + it2->first;
				if (it1->first == it2->first) {
					if (num2cnt[it1->first] >= 2) {
						sum2pair[sum2].push_back(make_pair(it1->first, it2->first));
					}
				} else {
					sum2pair[sum2].push_back(make_pair(it1->first, it2->first));
				}
			}
		}

		for (it1 = num2cnt.begin(); it1 != num2cnt.end(); it1 ++) {
			for (it2 = it1; it2 != num2cnt.end(); it2 ++) {
				int sum2 = it1->first + it2->first;
				int rem = target - sum2;
				if (sum2pair.find(rem) == sum2pair.end()) continue;

				vector<pair<int, int>> &vec = sum2pair[rem];
				int sz = vec.size();
				for (int k = 0; k < sz; k ++) {
					pair<int, int> &pa = vec[k];
					if (max(it1->first, it2->first) > min(pa.first, pa.second)) continue; // ensure no duplicate

					bool ok = check(pa.first, pa.second, it1->first, it2->first);

					vector<int> once;
					once.push_back(pa.first);
					once.push_back(pa.second);
					once.push_back(it1->first);
					once.push_back(it2->first);
					sort(once.begin(), once.end());
					if (ok) {
						ans.push_back(once);
					}
				}
				
			}
		}
		return ans;
    }
};