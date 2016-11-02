class Solution {
 public:
  // Get the maximum value of x and y
  int max(int x, int y) {
    if (x < y)
      return y;
    else
      return x;
  }

  int maxArea(vector<int>& height) {
    int result = 0;
    int l = 0;
    int r = height.size() - 1;
    while (l != r) {
      int val = (r - l) * (height[l] < height[r] ? height[l] : height[r]);
      result = (result > val ? result : val);
      if (height[l] <= height[r])
        l++;
      else
        r--;
    }
    return result;
  }
};