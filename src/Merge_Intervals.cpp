/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
bool cmp (const Interval &i1, const Interval &i2) {
	if (i1.start != i2.start) {
		return i1.start < i2.start;
	} else {
		return i2.end < i2.end;
	}
}

class Solution {
public:
	int n;
	vector<Interval> ans;

	bool judge(int s1, int t1, int s2, int t2) {
		bool ret = (min(t1, t2) - max(s1, s2)) >= 0;
		return ret;
	}

    vector<Interval> merge(vector<Interval> &intervals) {
        n = intervals.size();
		if (!n) return ans;

		sort(intervals.begin(), intervals.end(), cmp);

		int last = 0, from = intervals[0].start, to = intervals[0].end;

		for (int i = 1; i < n; i ++) {
			Interval &cur = intervals[i];
			bool overlap = judge(from, to, cur.start, cur.end);
			if (overlap) {
				to = max(to, cur.end);
			} else {
				ans.push_back(Interval(from, to));
				last = i;
				from = intervals[i].start;
				to = intervals[i].end;
			}
		}

		ans.push_back(Interval(from, to));
		return ans;
    }
};