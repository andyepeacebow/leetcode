#include <algorithm>
#include <numeric>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <sstream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
typedef long long ll;
#define mset(a, val) memset(a, val, sizeof(a))
#define up(i, s, t) for (ll i = (s); i < (t); i += 1)
#define down(i, s, t) for (ll i = (s); i > (t); i -= 1)
#define rd1(a) scanf("%d", &a)
#define rd2(a, b) scanf("%d %d", &a, &b)
#define rd3(a, b, c) scanf("%d %d %d", &a, &b, &c)
#define rd4(a, b, c, d) scanf("%d %d %d %d", &a, &b, &c, &d)
#define pii pair<int, int>
using namespace std;
const int MAXINT = 0x6fffffff;
const ll MAXLONG = (ll) 1 << 63 - 1;

class Solution {
public:
	double findMedianSortedArrays(int A[], int m, int B[], int n) {
		if (!m && !n) return 0.0;
		vector<int> vec;
		int ia = 0, ib = 0;
		while (ia < m && ib < n) {
			if (A[ia] <= B[ib]) {
				vec.push_back(A[ia]);
				ia ++;
			} else {
				vec.push_back(B[ib]);
				ib ++;
			}
		}
		while (ia < m) {
			vec.push_back(A[ia]);
			ia ++;
		}
		while (ib < n) {
			vec.push_back(B[ib]);
			ib ++;
		}
		double res;
		int idx = (m + n) / 2;
		if ((m + n) % 2 == 0) {
			res = (vec[idx - 1] + vec[idx]) / 2.0;
		} else {
			res = vec[idx];
		}
		return res;
	}
};

int main () {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	Solution sol;
	int a[] = {1, 4, 7};
	int b[] = {2, 5, 6};
	int res = sol.findMedianSortedArrays(a, 3, b, 3);
	cout << res << endl;
	return 0;
}