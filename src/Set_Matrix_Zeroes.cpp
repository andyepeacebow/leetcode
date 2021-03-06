class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
		if (matrix.size() == 0 || matrix[0].size() == 0) return;
		int m = matrix.size(), n = matrix[0].size();

        bool firstRowZero = false;
		for (int i = 0; i < n; i ++) {
			if (matrix[0][i] == 0) {
				firstRowZero = true;
				break;
			}
		}

		bool firstColZero = false;
		for (int i = 0; i < m; i ++) {
			if (matrix[i][0] == 0) {
				firstColZero = true;
				break;
			}
		}

		for (int i = 1; i < m; i ++) {
			for (int j = 1; j < n; j ++) {
				if (!matrix[i][j]) {
					matrix[i][0] = matrix[0][j] = 0;
				}
			}
		}

		for (int i = 1; i < m; i ++) {
			for (int j = 1; j < n; j ++) {
				if (!matrix[i][0] || !matrix[0][j]) {
					matrix[i][j] = 0;
				}
			}
		}

		if (firstRowZero) {
			for (int i = 0; i < n; i ++) {
				matrix[0][i] = 0;
			}
		}

		if (firstColZero) {
			for (int i = 0; i < m; i ++) {
				matrix[i][0] = 0;
			}
		}
    }
};