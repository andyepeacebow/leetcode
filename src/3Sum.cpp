class Solution {
public:
	unordered_map<int, int> num2Cnt;
	vector<vector<int>> ans;
	set<int> ss;

    vector<vector<int> > threeSum(vector<int> &num) {
		int n = num.size();
		if (n < 3) return ans;
		
		for (int i = 0; i < n; i ++) {
			num2Cnt[ num[i] ] ++;
			ss.insert( num[i] );
		}

		set<int>::iterator it1, it2;
		for (it1 = ss.begin(); it1 != ss.end(); it1 ++) {
			for (it2 = it1; it2 != ss.end(); it2 ++) {
				if (*it1 == *it2 && num2Cnt[*it1] < 2) continue;

				int sum2 = *it1 + *it2;
				int rem = 0 - sum2;
				if (rem < *it1 || rem < *it2) continue;
				if (ss.find(rem) == ss.end()) continue;
				if (rem == *it1 && rem == *it2 && num2Cnt[rem] < 3) continue;
				if ( (rem == *it1 || rem == *it2) && num2Cnt[rem] < 2 ) continue;

				vector<int> once;
				once.push_back(*it1);
				once.push_back(*it2);
				once.push_back(rem);
				sort(once.begin(), once.end());
				ans.push_back(once);
			}
		}

		return ans;
    }
};