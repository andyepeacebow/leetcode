class Solution {
public:
	string s;
	bool isNeg;
	int len;

	void trim() {
		// trim preceding spaces
		int idx = 0;
		while (idx < s.length() && s[idx] == ' ') idx ++;
		s = s.substr(idx);

		// only keep the sign and digits part
		idx = 0;
		while (idx < s.length() && (s[idx] == '+' || s[idx] == '-' || isdigit(s[idx]))) idx ++;

		s = s.substr(0, idx);
	}

	bool checkChar() {
		for (int i = 0; i < s.length(); i ++) {
			if (!isdigit(s[i])) {
				return false;
			}
		}
		return true;
	}

	bool checkRange() {
		int imin = std::numeric_limits<int>::min(); // make it positive
		int imax = std::numeric_limits<int>::max();
		char buf[100];
		if (isNeg) {
			sprintf(buf, "%d", imin);
			strcpy(buf, buf + 1); // remove '-'
			if (strlen(buf) < s.length()) return false;
			if (strlen(buf) == s.length() && strcmp(buf, s.c_str()) < 0) return false;
			return true;
		} else {
			sprintf(buf, "%d", imax);
			if (strlen(buf) < s.length()) return false;
			if (strlen(buf) == s.length() && strcmp(buf, s.c_str()) < 0) return false;
			return true;
		}
	}

	int toInt() {
		int ret = 0;
		for (int i = 0; i < s.length(); i ++) {
			ret = ret * 10 + s[i] - '0';
		}
		if (isNeg) {
			ret *= -1;
		}
		return ret;
	}

    int atoi(const char *str) {
		len = strlen(str);
		s.assign(str, str + len);
		trim();
		
		isNeg = false;
		if (s.length() > 0 && !isdigit(s[0])) {
			isNeg = s[0] == '-';
			s = s.substr(1);
		}
		if (s.length() == 0) return 0;

		bool ok = checkChar();
		if (!ok) return 0;

		ok = checkRange();
		if (!ok) {
			return isNeg ? std::numeric_limits<int>::min() : std::numeric_limits<int>::max();
		}

		int res = toInt();
		return res;
    }
};