#include <vector>

using namespace std;

class Solution {
 public:
  struct Job {
    int start;
    int end;
    int profit;
    Job(int startTime, int endTime, int profit)
        : start(startTime), end(endTime), profit(profit) {}
  };

  int getNextJob(int index, vector<Job>& jobs) {
    for (int i = index; i < jobs.size(); i++) {
      if (jobs[i].start >= jobs[index].end) {
        return i;
      }
    }
    return -1;
  }
  int profitOfLaterJobs(int index, vector<int>& dp) {
    if (index > 0) {
      return dp[index];
    } else {
      return 0;
    }
  }
  vector<Job> prepareJobs(vector<int>& startTime,
                          vector<int>& endTime,
                          vector<int>& profit) {
    vector<Job> jobs;
    for (int i = 0; i < startTime.size(); i++) {
      jobs.push_back(Job(startTime[i], endTime[i], profit[i]));
    }
    return jobs;
  }
  int jobScheduling(vector<int>& startTime,
                    vector<int>& endTime,
                    vector<int>& profit) {
    int length = startTime.size();
    vector<int> dp = vector<int>(length);
    vector<Job> jobs(prepareJobs(startTime, endTime, profit));
    sort(jobs.begin(), jobs.end(),
         [](const Job& lhs, const Job& rhs) { return lhs.start <= rhs.start; });
    dp[length - 1] = jobs[length - 1].profit;
    for (int i = length - 2; i >= 0; i--) {
      int indexOfNextJob = getNextJob(i, jobs);
      dp[i] = max(profitOfLaterJobs(indexOfNextJob, dp) + jobs[i].profit,
                  dp[i + 1]);
    }
    return dp[0];
  }
};