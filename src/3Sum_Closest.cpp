class Solution {
public:


    int threeSumClosest(vector<int> &num, int target) {

		if (num.size() <= 3) {
			int res = accumulate(num.begin(), num.end(), 0);
			return res;
		}
        sort(num.begin(), num.end());
		vector<int> vec;
		int n = num.size();
		for (int i = 0; i < n; i ++) {
			if (i > 2 && num[i - 3] == num[i]) continue;
			
			vec.push_back(num[i]);
		}
		
		n = vec.size();
		int mindif = 0x6fffffff;
		int res = -1;
		for (int i = 0; i < n; i ++) {
			for (int j = i + 1; j < n; j ++) {
				int sum2 = vec[i] + vec[j];

				int rem = target - sum2;
				int idx = lower_bound(vec.begin(), vec.end(), rem) - vec.begin();

				if (idx >= n) idx --;

				
				if (idx < 0 || idx >= n || idx == i || idx == j) continue;

				int sum3 = sum2 + vec[idx];
				int dif = abs(sum3 - target);
				if (dif < mindif) {
					mindif = dif;
					res = sum3;
				}
				if (dif == 0) return res;

			}
		}
		return res;
    }
};