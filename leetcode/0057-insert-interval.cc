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
  int max(int a, int b) {
    if (a > b)
      return a;
    else
      return b;
  }

  int search(vector<Interval>& intervals, Interval newInterval) {
    int s = 0, e = intervals.size() - 1, mid = e / 2;
    while (s <= e) {
      mid = (e + s) / 2;
      if (intervals[mid].start <= newInterval.start) {
        s = mid + 1;
      } else {
        e = mid - 1;
      }
    }
    return s;
  }

  vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
    // Insert
    if (intervals.size() == 0) {
      intervals.push_back(newInterval);
      return intervals;
    } else if (newInterval.start >= (*(intervals.end() - 1)).start) {
      intervals.push_back(newInterval);
    } else {
      int pos = search(intervals, newInterval);
      auto it_insert = intervals.begin();
      for (int i = 0; i < pos; i++) {
        it_insert++;
      }
      intervals.insert(it_insert, newInterval);
    }
    // Merge
    for (auto it = intervals.begin(); it != intervals.end(); ++it) {
      auto start = it;
      auto next = it + 1;
      auto end = it;
      while (next != intervals.end() && (*it).end >= (*next).start) {
        (*it).end = max((*it).end, (*next).end);
        next++;
        end++;
      }
      if (end != start) {
        if (start + 1 == end)
          intervals.erase(end);
        else
          intervals.erase(start + 1, end + 1);
      }
    }

    return intervals;
  }
};