class Solution {
public:
    string getPermutation(int n, int k) {
        if (!n) return "";

		int comb = 1;
		vector<int> vec;
		for (int i = 1; i < n; i ++) {
			comb *= i;
			vec.push_back(i);
		}
		vec.push_back(n);

		string ans = "";
		for (int i = 0; i < n; i ++) {
			int v = (k - 1) / comb;
			ans += '0' + vec[v];
			vec.erase(vec.begin() + v);
			k -= v * comb;
			if (n - i - 1 > 0) {
				comb /= (n - i - 1);
			}
		}

		return ans;
    }
};