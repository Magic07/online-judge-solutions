#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> filterRestaurants(vector<vector<int>>& restaurants,
                                int veganFriendly,
                                int maxPrice,
                                int maxDistance) {
    vector<int> answer;
    sort(restaurants.begin(), restaurants.end(),
         [](const vector<int>& lhs, const vector<int>& rhs) {
           if (lhs[1] < rhs[1] || ((lhs[1] == rhs[1]) && (lhs[0] < rhs[0]))) {
             return true;
           } else {
             return false;
           }
         });
    for (vector<int>& r : restaurants) {
      if (r[3] <= maxPrice && r[4] <= maxDistance) {
        if (veganFriendly == 0) {
          answer.push_back(r[0]);
        } else {
          if (r[2] == 1) {
            answer.push_back(r[0]);
          }
        }
      }
    }
    reverse(answer.begin(), answer.end());
    return answer;
  }
};