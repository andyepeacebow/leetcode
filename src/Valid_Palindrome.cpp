class Solution {
public:

	bool isvalidchar(char ch) {
		if (isalpha(ch) || isdigit(ch)) return true;
		return false;
	}

    bool isPalindrome(string s) {
		int len = s.length();
        if (len == 0) return true;

		int f = 0, t = len - 1;
		while (f < t) {
			while (f < t && !isvalidchar(s[f])) {
				f ++;
			}
			while (f < t && !isvalidchar(s[t])) {
				t --;
			}
			
			if (tolower(s[f]) != tolower(s[t])) return false;
			f ++, t --;
		}

		return true;
    }
};