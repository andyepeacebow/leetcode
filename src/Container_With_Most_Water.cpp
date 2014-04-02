class Solution {
public:
    int maxArea(vector<int> &height) {
        int n = height.size();
		if (n < 2) return 0;

		int s = 0, t = n - 1;
		int res = -1;
		while (s < t) {
			int once = min(height[s], height[t]) * (t - s);
			res = max(res, once);

			if (height[s] >= height[t]) {
				t --;
			} else {
				s ++;
			}
		}

		return res;
    }
};