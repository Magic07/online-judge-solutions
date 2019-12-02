/**
 * // This is Sea's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Sea {
 *   public:
 *     bool hasShips(vector<int> topRight, vector<int> bottomLeft);
 * };
 */

class Solution {
 public:
  vector<int> middle(const vector<int>& topRight,
                     const vector<int>& bottomLeft) {
    int x = bottomLeft[0] + (topRight[0] - bottomLeft[0]) / 2;
    if ((topRight[0] - bottomLeft[0]) % 2 == 1)
      x++;
    int y = bottomLeft[1] + (topRight[1] - bottomLeft[1]) / 2;
    if ((topRight[1] - bottomLeft[1]) % 2 == 1)
      y++;
    vector<int> mid = {x, y};
    return mid;
  }
  int countShips(Sea sea, vector<int> topRight, vector<int> bottomLeft) {
    if (topRight[0] < bottomLeft[0] || topRight[1] < bottomLeft[1])
      return 0;
    if (!sea.hasShips(topRight, bottomLeft))
      return 0;
    if (topRight[0] == bottomLeft[0] && topRight[1] == bottomLeft[1])
      return 1;
    vector<int> mid = middle(topRight, bottomLeft);
    return countShips(sea, topRight, mid) +
           countShips(sea, {mid[0] - 1, topRight[1]}, {bottomLeft[0], mid[1]}) +
           countShips(sea, {mid[0] - 1, mid[1] - 1}, bottomLeft) +
           countShips(sea, {topRight[0], mid[1] - 1}, {mid[0], bottomLeft[1]});
  }
};