class Solution {
public:
	vector<vector<char>> bo;
	unordered_set<char> row[9], col[9], block[9];
	
	int calcBlockId(int x, int y) {
		int ret = x / 3 * 3 + y / 3;
		return ret;
	}

	void move(int &x, int &y) {
		y ++;
		if (y >= 9) {
			y = 0;
			x ++;
		}
	}

	bool dfs(int x, int y) {
		if (x >= 9) return true;

		char ch = bo[x][y];
		int xx = x, yy = y;
		move(xx, yy);
		if (ch != '.') {
			bool ret = dfs(xx, yy);
			return ret;
		}

		int bid = calcBlockId(x, y);
		for (char i = '1'; i <= '9'; i ++) {

			if (row[x].find(i) != row[x].end() || col[y].find(i) != col[y].end() 
				|| block[bid].find(i) != block[bid].end()) {
					continue;
			}

			row[x].insert(i);
			col[y].insert(i);
			block[bid].insert(i);
			bool ret = dfs(xx, yy);
			if (ret) {
				bo[x][y] = i;
				return true;
			}
			row[x].erase(i);
			col[y].erase(i);
			block[bid].erase(i);
		}

		return false;
	}

    void solveSudoku(vector<vector<char> > &board) {
		if (board.size() != 9 || board[0].size() != 9) return;

        bo = board;

		for (int i = 0; i < 9; i ++) {
			for (int j = 0; j < 9; j ++) {
				char ch = bo[i][j];
				if (ch == '.') continue;

				int bid = calcBlockId(i, j);
				row[i].insert(ch);
				col[j].insert(ch);
				block[bid].insert(ch);
			}
		}

		dfs(0, 0);
		board = bo;
    }
};