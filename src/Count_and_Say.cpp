class Solution {
public:
    string countAndSay(int n) {
        if (n < 1) return "";

		string str[2];
		str[0] = "1";
		int pre = 0, nxt = 1;

		for (int i = 1; i < n; i ++) {
			string &s1 = str[pre];
			string &s2 = str[nxt];
			s2.clear();
			int len1 = s1.length();
			char ch = s1[0];
			int j = 0;
			while(j < len1) {
				int cnt = 0;
				while (j < len1 && ch == s1[j]) {
					j ++;
					cnt ++;
				}

				s2 += ('0' + cnt);
				s2 += ch;

				if (j >= len1) break;
				ch = s1[j];
			}

			swap(pre, nxt);
		}

		return str[pre];
    }
};