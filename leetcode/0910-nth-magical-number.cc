class Solution {
 public:
  int nthMagicalNumber(int N, int A, int B) {
    long long lcm = std::lcm((long long)A, (long long)B);
    int nInOneRound = lcm / A + lcm / B - 1;
    int times = N / nInOneRound;
    long long answerBase = times * lcm;
    long long answer = answerBase, nextA = answerBase + A,
              nextB = answerBase + B;
    int remainN = N - times * nInOneRound;
    while (remainN > 0) {
      if (nextA == nextB) {
        answer = nextA;
        nextA += A;
        nextB += B;
      } else if (nextA < nextB) {
        answer = nextA;
        nextA += A;
      } else {
        answer = nextB;
        nextB += B;
      }
      remainN--;
    }
    return answer % 1000000007;
  }
};