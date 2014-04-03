class Solution {
public:
	vector<int> ans;

	vector<int> mul(vector<int> &vec, int x) {
		vector<int> res = vec;
		int ca = 0;
		for (int i = res.size() - 1; i >= 0; i --) {
			res[i] = res[i] * x + ca;
			ca = res[i] / 10;
			res[i] %= 10;
		}
		if (ca) {
			res.insert(res.begin(), ca);
		}
		return res;
	}

	void add(vector<int> &res, vector<int> &x) {
		int dif = x.size() - res.size();
		for (int i = 0; i < dif; i ++) {
			res.insert(res.begin(), 0);
		}
		int ca = 0;
		for (int i = max(res.size(), x.size()) - 1; i >= 0; i --) {
			res[i] = res[i] + x[i] + ca;
			ca = res[i] / 10;
			res[i] %= 10;
		}
		if (ca) {
			res.insert(res.begin(), ca);
		}
	}

    string multiply(string num1, string num2) {
        if (num1.size() == 0 || num2.size() == 0) return "";

		vector<int> ar1;
		for (int i = 0; i < num1.size(); i ++) {
			ar1.push_back(num1[i] - '0');
		}
		for (int i = num2.size() - 1; i >= 0; i --) {
			vector<int> once = mul(ar1, num2[i] - '0');
			for (int j = num2.size() - 1; j > i; j --) once.push_back(0);
			add(ans, once);
		}

		
		while (ans.size() > 1 && ans[0] == 0) {
			ans.erase(ans.begin());
		}
		string res = "";
		for (int i = 0; i < ans.size(); i ++) {
			res += '0' + ans[i];
		}
		return res;
    }
};