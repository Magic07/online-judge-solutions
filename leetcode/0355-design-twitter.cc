class Twitter {
 public:
  int currentTweetIndex = 1;
  std::unordered_map<int, int> tweets;    // Key is realID, value is tweet ID.
  std::unordered_map<int, int> tweetMap;  // Key is twitter ID, value is userID.
  std::unordered_map<int, std::vector<int>>
      follows;  // Key is userID, value is his/her follerees.
  std::unordered_map<int, std::vector<int>>
      userTweets;  // Key is user ID, value is tweet ID.

  /** Initialize your data structure here. */
  Twitter() {}

  /** Compose a new tweet. */
  void postTweet(int userId, int tweetId) {
    tweetMap[tweetId] = userId;
    tweets[currentTweetIndex] = tweetId;
    userTweets[userId].push_back(currentTweetIndex);
    currentTweetIndex++;
  }

  /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item
   * in the news feed must be posted by users who the user followed or by the
   * user herself. Tweets must be ordered from most recent to least recent. */
  vector<int> getNewsFeed(int userId) {
    vector<int> result;
    vector<int> tweetCandidats;
    vector<int>& followee_vector = follows[userId];
    for (auto it = followee_vector.begin(); it != followee_vector.end(); it++) {
      vector<int>& userTweet = userTweets[*it];
      tweetCandidats.insert(tweetCandidats.end(), userTweet.begin(),
                            userTweet.end());
    }
    tweetCandidats.insert(tweetCandidats.end(), userTweets[userId].begin(),
                          userTweets[userId].end());
    std::sort(tweetCandidats.begin(), tweetCandidats.end());
    int i = 0;
    for (auto it = tweetCandidats.rbegin();
         it != tweetCandidats.rend() && i < 10; it++, i++) {
      result.push_back(tweets[*it]);
    }
    return result;
  }

  /** Follower follows a followee. If the operation is invalid, it should be a
   * no-op. */
  void follow(int followerId, int followeeId) {
    if (followerId == followeeId) {
      return;
    }
    std::vector<int>& followee_vector = follows[followerId];
    if (std::find(followee_vector.begin(), followee_vector.end(), followeeId) !=
        followee_vector.end()) {
      return;
    }
    follows[followerId].push_back(followeeId);
  }

  /** Follower unfollows a followee. If the operation is invalid, it should be a
   * no-op. */
  void unfollow(int followerId, int followeeId) {
    auto followees = follows.find(followerId);
    if (followees == follows.end()) {
      return;
    } else {
      auto followee_it = std::find(followees->second.begin(),
                                   followees->second.end(), followeeId);
      if (followee_it != followees->second.end()) {
        followees->second.erase(followee_it);
      }
    }
  }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter obj = new Twitter();
 * obj.postTweet(userId,tweetId);
 * vector<int> param_2 = obj.getNewsFeed(userId);
 * obj.follow(followerId,followeeId);
 * obj.unfollow(followerId,followeeId);
 */