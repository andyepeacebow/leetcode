class Solution {
public:
	unordered_map<char, int> ch2cntT, ch2cntS;
	int lens, lent;

    string minWindow(string S, string T) {
        for (int i = 0; i < T.length(); i ++) {
			char ch = T[i];
			ch2cntT[ch] ++;
		}

		lens = S.length();
		lent = T.length();
		int s = 0, t = -1;
		bool found = false;
		int res_s, res_len = lens + 1;
		int cnt = 0, target = ch2cntT.size();
		while (s < lens) {
			while (t < lens && cnt < target) {
				t ++;
				if (t >= lens) break;
				char ch = S[t];
				ch2cntS[ch] ++;
				if (ch2cntS[ch] == ch2cntT[ch]) {
					cnt ++;
				}
			}

			if (t < lens) {
				found = true;
			} else {
				break;
			}

			int once = t - s + 1;
			if (once < res_len) {
				res_len = once;
				res_s = s;
			}
			ch2cntS[ S[s] ] --;
			if (ch2cntS[ S[s] ] == ch2cntT[ S[s] ] - 1) {
				cnt --;
			}
			s ++;
		}

		string ans = found ? S.substr(res_s, res_len) : "";
		return ans;
    }
};