class Solution {
public:
	vector<int> from, back, arr;
	int n;

    int candy(vector<int> &ratings) {
		arr = ratings;
        n = ratings.size();
		from.resize(n, 0);
		back.resize(n, 0);

		for (int i = 1; i < n; i ++) {
			if (ratings[i - 1] < ratings[i]) {
				from[i] = from[i - 1] + 1;
			} else { // from[i - 1] > from[i]
				from[i] = 0;
			}
		}

		for (int i = n - 2; i >= 0; i --) {
			if (ratings[i] > ratings[i + 1]) {
				back[i] = back[i + 1] + 1;
			} else {
				back[i] = 0;
			}
		}

		int res = 0;
		for (int i = 0; i < n; i ++) {
			int once = 1 + max(from[i], back[i]);
			res += once;
		}
		return res;
    }
};