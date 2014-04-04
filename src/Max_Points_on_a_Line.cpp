/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Line {
public:
	double slope, indent;
	double ver;
	bool isVer;
	Line (double s, double i, bool _isver, double _ver): slope(s), indent(i), isVer(_isver), ver(_ver) {}

	bool operator < (const Line &other) const {
		if (slope != other.slope) {
			return slope < other.slope;
		} else {
			return indent < other.indent;
		}
	}
};
class Solution {
public:
	vector<double> veck, vecc;
	set<Line> lines;
	int np;

	bool judge(Line &line, Point &point) {
		if (line.isVer) {
			if (line.ver == point.x) return true;
			else return false;
		}
		double err = 1e-6;
		bool ret = abs(point.x * line.slope + line.indent - point.y) <= err;
		return ret;
	}

    int maxPoints(vector<Point> &points) {
        veck.clear(), vecc.clear();
		np = points.size();
		if (np <= 1) return np;

		for (int i = 0; i < np; i ++) {
			Point &p1 = points[i];
			for (int j = i + 1; j < np; j ++) {
				Point &p2 = points[j];

				double k = 0.0, c = 0.0, ver = 0.0;
				bool isVer = false;
				if (p1.x == p2.x) {
					isVer = true;
					ver = p1.x;
				} else {
					k = 1.0 * (p1.y - p2.y) / (p1.x - p2.x);
					c = p1.y - p1.x * k;
				}
				
				
				lines.insert(Line(k, c, isVer, ver));
			}
		}

		if (lines.size() == 0) {
			return points.size();
		} else {
			int res = 0;
			set<Line>::iterator it;
			for (it = lines.begin(); it != lines.end(); it ++) {
				Line line = *it;
				int once = 0;
				for (int j = 0; j < points.size(); j ++) {
					bool onLine = judge(line, points[j]);
					if (onLine) {
						once ++;
					}
				}
				res = max(res, once);
			}

			return res;
		}
    }
};