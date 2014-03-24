//class Solution {
//public:
//
//	double fastPow(double x, long long n) {
//		if (n < 0) n *= -1;
//		double res = 1.0;
//		while (n) {
//			if (n & 1) {
//				res *= x;
//			}
//			x *= x;
//			n >>= 1;
//		}
//
//		return res;
//	}
//
//    double pow(double x, int n) {
//		double res = 1.0;
//		res = fastPow(x, n);
//		if (n < 0) {
//			if (x == 0.0) return 0.0;
//			else res = 1 / res;
//		}
//		return res;
//    }
//};