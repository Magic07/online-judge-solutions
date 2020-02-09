#include <unordered_map>
#include <vector>

class TweetCounts {
 public:
  unordered_map<string, vector<int>> tweets;
  TweetCounts() {}

  void recordTweet(string tweetName, int time) {
    tweets[tweetName].push_back(time);
  }

  vector<int> getTweetCountsPerFrequency(string freq,
                                         string tweetName,
                                         int startTime,
                                         int endTime) {
    if (endTime < startTime) {
      endTime = startTime;
    }
    int interval(0);
    if (freq == "minute") {
      interval = 60;
    } else if (freq == "hour") {
      interval = 3600;
    } else if (freq == "day") {
      interval = 86400;
    }
    vector<int> answer;
    vector<int>& tweetTime = tweets[tweetName];
    sort(tweetTime.begin(), tweetTime.end());
    int answerOfCurrentInterval(0);
    int startOfInterval(startTime);
    int endOfInterval(startTime + interval - 1);
    for (int t : tweetTime) {
      if (t < startOfInterval) {
        continue;
      } else if (t <= endOfInterval) {
        if (t <= endTime) {
          answerOfCurrentInterval++;
        } else {
          answer.push_back(answerOfCurrentInterval);
          return answer;
        }
      } else {  // t>endOfInterval.
                // Finish current interval.
        answer.push_back(answerOfCurrentInterval);
        startOfInterval += interval;
        endOfInterval += interval;
        if(startOfInterval>endTime){
          return answer;
        }
        answerOfCurrentInterval = 0;
        // Skip other intervals before `t`.
        while (t > endOfInterval && endTime > endOfInterval) {
          answer.push_back(0);
          startOfInterval += interval;
          endOfInterval += interval;
        }
        if (t <= endOfInterval) {
          if (t <= endTime) {
            answerOfCurrentInterval++;
          } else {
            answer.push_back(answerOfCurrentInterval);
            return answer;
          }
        } else {
          answer.push_back(answerOfCurrentInterval);
          return answer;
        }
      }
    }
    answer.push_back(answerOfCurrentInterval);
    while (endOfInterval < endTime) {
      answer.push_back(0);
      endOfInterval += interval;
    }
    return answer;
  }
};

/**
 * Your TweetCounts object will be instantiated and called as such:
 * TweetCounts* obj = new TweetCounts();
 * obj->recordTweet(tweetName,time);
 * vector<int> param_2 =
 * obj->getTweetCountsPerFrequency(freq,tweetName,startTime,endTime);
 */