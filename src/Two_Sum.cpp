class Solution {
public:
	vector<int> ans;

    vector<int> twoSum(vector<int> &numbers, int target) {
		int n = numbers.size();
		if (n < 2) return ans;

		vector<pair<int, int>> vec;
		for (int i = 0; i < n; i ++) {
			vec.push_back(make_pair(numbers[i], i));
		}
        sort(vec.begin(), vec.end());
		
		for (int i = 0; i < n; i ++) {
			int rem = target - vec[i].first;
			int idx = lower_bound(vec.begin(), vec.end(), make_pair(rem, -1)) - vec.begin();
			if (idx < n && vec[i].second != vec[idx].second && vec[i].first + vec[idx].first == target) {
				ans.push_back(vec[i].second < vec[idx].second ? vec[i].second : vec[idx].second);
				ans.push_back(vec[i].second > vec[idx].second ? vec[i].second : vec[idx].second);
				ans[0] += 1;
				ans[1] += 1;
				return ans;
			}
		}
    }
};