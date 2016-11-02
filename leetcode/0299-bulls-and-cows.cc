class Solution {
 public:
  string getHint(string secret, string guess) {
    int length = secret.size();
    // Flags for secret and guess.
    bool paired_secret[length];
    bool paired_guess[length];
    memset(paired_secret, 0, length * sizeof(bool));
    memset(paired_guess, 0, length * sizeof(bool));

    // Found bulls
    int bulls = 0;
    for (int i = 0; i < length; i++) {
      if (secret.at(i) == guess.at(i)) {
        bulls++;
        paired_secret[i] = true;
        paired_guess[i] = true;
      }
    }

    // Found cows
    int cows = 0;
    for (int i = 0; i < length; i++) {
      if (paired_secret[i]) {
        continue;
      }
      for (int j = 0; j < length; j++) {
        if (!paired_guess[j] && secret.at(i) == guess.at(j)) {
          cows++;
          paired_guess[j] = true;
          paired_secret[i] = true;
          break;
        }
      }
    }

    return std::to_string(bulls) + "A" + std::to_string(cows) + "B";
  }
};