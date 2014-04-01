class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
		int n = height.size();
		if (!n) return 0;

        int idx = 0;
		int ans = -1;
		stack<int> st;
		while (idx < n) {
			int h = height[idx];
			if (st.empty() || h > height[st.top()]) {
				st.push(idx);
				idx ++;
			} else {
				int tp = st.top();
				st.pop();
				int once;
				if (st.empty()) {
					once = height[tp] * idx;
				} else {
					once = height[tp] * (idx - st.top() - 1);
				}

				ans = max(once, ans);
			}
		}

		while (st.empty() == false) {
			int tp = st.top();
			st.pop();
			int once;
			if (st.empty()) {
				once = height[tp] * idx;
			} else {
				once = height[tp] * (idx - st.top() - 1);
			}

			ans = max(once, ans);
		}

		return ans;
    }
};