class Solution {
public:
	vector<vector<char>> mat;

    string convert(string s, int nRows) {
		int n = s.length();
		if (n == 0 || nRows == 0) return "";
		if (nRows == 1) return s;

        int wid = ceil(1.0 * n / (2 * nRows - 2)) * (nRows - 1);
		vector<char> tmp(wid, 0);
		for (int i = 0; i < nRows; i ++) {
			mat.push_back(tmp);
		}

		int dir = 0, idx = 0;
		int x = 0, y = 0;
		while (idx < n) {
			mat[x][y] = s[idx];
			idx ++;

			if (dir == 0) {
				if (x + 1 < nRows) {
					x ++;
				} else {
					dir = 1;
					x --, y ++;
				}
			} else {
				if (x - 1 >= 0) {
					x --, y ++;
				} else {
					dir = 0;
					x ++;
				}
			}
		}

		string ans;
		for (int i = 0; i < nRows; i ++) {
			for (int j = 0; j < wid; j ++) {
				if (mat[i][j] != 0) ans += mat[i][j];
			}
		}

		return ans;
    }
};