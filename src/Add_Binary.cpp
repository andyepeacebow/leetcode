class Solution {
public:
    string addBinary(string a, string b) {
        if (a.length() == 0 || b.length() == 0) {
			return "";
		}

		if (a.length() > b.length()) {
			swap(a, b);
		}

		// a is shorter
		int la = a.length();
		int lb = b.length();

		for (int i = la; i < lb; i ++) {
			a = '0' + a;
		}

		int ca = 0;
		for (int i = lb - 1; i >= 0; i --) {
			b[i] += a[i] - '0' + ca;
			if (b[i] - '0' >= 2) {
				ca = 1;
			} else {
				ca = 0;
			}
			b[i] = (b[i] - '0') % 2 + '0';
		}

		if (ca) {
			b.insert(b.begin(), '1');
		}

		return b;
    }
};