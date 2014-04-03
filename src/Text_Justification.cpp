class Solution {
public:
	vector<int> lines, vecWordLen, vecWordNum;
	vector<string> ans;
	int nw;

    vector<string> fullJustify(vector<string> &words, int L) {
        nw = words.size();
		if (!nw) return ans;
		int wordLen = 0, wordNum = 0;
		int from = 0;
		for (int i = 0; i < nw; i ++) {
			int len = wordLen + wordNum - 1;
			if (len + words[i].length() + 1 > L) {
				lines.push_back(from);
				vecWordLen.push_back(wordLen);
				vecWordNum.push_back(wordNum);
				from = i;
				wordLen = wordNum = 0;
			}

			wordLen += words[i].length();
			wordNum ++;
		}
		if (wordNum) {
			lines.push_back(from);
			vecWordLen.push_back(wordLen);
			vecWordNum.push_back(wordNum);
		}

		for (int i = 0; i < lines.size(); i ++) {
			bool lastLine = i == lines.size() - 1;
			int blanks = L - vecWordLen[i];
			int wn = vecWordNum[i];
			int bLen = ceil(1.0 * blanks / (wn - 1));

			string once;
			int s = lines[i];
			for (int j = 0; j < vecWordNum[i]; j ++) {
				once += words[s + j];
				if (wn == 1) break;
				once += string(lastLine ? 1 : bLen, ' ');
				blanks -= bLen;
				wn --;
				bLen = ceil( 1.0 * blanks / ( (wn - 1) == 0 ? 1 : (wn - 1)) );
			}
			while (once.length() < L) {
				once.push_back(' ');
			}
			ans.push_back(once);
		}

		return ans;
    }
};