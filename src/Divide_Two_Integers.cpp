class Solution {
public:
	bool isNeg;
	int a, b;

	void toSameSign() {
		isNeg = false;
		if (a < 0 && b > 0) {
			isNeg = true;
			b = 0 - b;
		}
		if (a > 0 && b < 0) {
			isNeg = true;
			a = 0 - a;
		}
	}

	bool overflow(int x, int y) {
		bool ret;
		if (x < 0) {
			ret = x < (std::numeric_limits<int>::min() - y);
		} else {
			ret = x > (std::numeric_limits<int>::max() - y);
		}
		return ret;
	}

	int div(vector<int> &sum, vector<int> &mul) {
		int idx = sum.size() - 1;
		int ret = 0;
		while (idx >= 0) {
			if (a < 0) {
				if (a <= sum[idx]) {
					a -= sum[idx];
					ret += mul[idx];
				}
			} else {
				if (a >= sum[idx]) {
					a -= sum[idx];
					ret += mul[idx];
				}
			}
			idx --;
			if (a == 0) {
				break;
			}
		}

		return ret;
	}
	
    int divide(int dividend, int divisor) {
        if (dividend == 0 || divisor == 0) return 0;
		if (divisor == 1) {
			return dividend;
		}
		if (divisor == -1) { // cannot deal with (minInt / -1)
			return 0 - dividend;
		}

		a = dividend;
		b = divisor;

		toSameSign();

		vector<int> sum(1, b), mul(1, 1);
		int cur = b;
		for (int i = 2; ; i += i) {
			bool ok = overflow(cur, cur);
			if (ok) break;
			cur += cur;
			sum.push_back(cur);
			mul.push_back(i);
		}

		int res = div(sum, mul);
		if (isNeg) {
			res = 0 - res;
		}
		return res;
    }
};