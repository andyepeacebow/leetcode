class Solution {
public:
	string str;

	void trim(string &s, char toTrim) {
		int idx = 0;
		while (idx < s.length() && s[idx] == toTrim) idx ++;
		s = s.substr(idx);

		idx = s.length() - 1;
		while (idx >= 0 && s[idx] == toTrim) idx --;
		s = s.substr(0, idx + 1);
	}

	void trimSign(string &s) {
		if (s.length() > 0 && (s[0] == '+' || s[0] == '-')) {
			s = s.substr(1);
		}
	}

	// cannot contain '.'
	bool checkInt(string &s) {
		if (s.length() == 0) return false;
		for (int i = 0; i < s.length(); i ++) {
			if (!isdigit(s[i])) return false;
		}
		return true;
	}

	bool checkIntOrFloat(string &s) {
		if (s.length() == 0 || (s.length() == 1 && s[0] == '.')) return false;
		int cntDot = 0;
		for (int i = 0; i < s.length(); i ++) {
			if (! (isdigit(s[i]) || s[i] == '.' ) ) return false;
			cntDot += s[i] == '.';
		}
		bool ret = cntDot <= 1;
		return ret;
	}

	void removeSign(string &s) {
		if (s.length() > 0 && (s[0] == '+' || s[0] == '-')) {
			s = s.substr(1);
		}
	}

    bool isNumber(const char *s) {
        str.assign(s);

		trim(str, ' ');
		if (str.length() == 0) return false;

		int idxE = str.find('e');
		bool isE = idxE != str.npos;
		if (isE) {
			string first = str.substr(0, idxE);
			string second = str.substr(idxE + 1);
			if (first.length() == 0 || second.length() == 0) return false;
			trimSign(first);
			trimSign(second);
			bool ok = checkInt(first) || checkIntOrFloat(first);
			if (!ok) return false;
			ok = checkInt(second);
			if (!ok) return false;
		} else {
			trimSign(str);
			bool ok = checkIntOrFloat(str);
			if (!ok) return false;
		}

		return true;
    }
};