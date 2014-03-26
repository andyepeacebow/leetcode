/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
	int n;
	vector<Interval> ans;
	
	bool judge(int s1, int t1, int s2, int t2) {
		bool ret = (min(t1, t2) - max(s1, s2)) >= 0;
		return ret;
	}

    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
		n = intervals.size();
		if (n == 0) {
			ans.push_back(newInterval);
			return ans;
		}

		int s = -1, t = -1;
		for (int i = 0; i < n; i ++) {
			Interval &one = intervals[i];
			bool overlap = judge(one.start, one.end, newInterval.start, newInterval.end);
			if (overlap && s == -1) {
				s = i;
			}
			if (overlap) {
				t = i;
			}
		}

		bool toMerge = true;
		Interval merged;
		if (s != -1) { // need to merge
			merged = Interval(min(newInterval.start, intervals[s].start), max(newInterval.end, intervals[t].end));
		} else {
			toMerge = false;
		}

		if (toMerge) {
			for (int i = 0; i < n; i ++) {
				if (i < s || i > t) {
					ans.push_back(intervals[i]);
				}
				if (i == s) {
					ans.push_back(merged);
				}
			}
		} else {
			ans = intervals;
			if (newInterval.start > intervals[n - 1].end) {
				ans.push_back(newInterval);
			} else {
				for (int i = 0; i < n; i ++) {
					Interval &one = intervals[i];
					if (one.start > newInterval.end) {
						ans.insert(ans.begin() + i, newInterval);
						break;
					}
				}
			}
		}
		return ans;

    }
};