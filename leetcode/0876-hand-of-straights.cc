class Solution {
  struct List {
    int val;
    List* next;
    List(int val) : val(val), next(nullptr) {}
  };

 public:
  bool isNStraightHand(vector<int>& hand, int W) {
    if (hand.size() % W != 0) {
      return false;
    }
    if (W == 1) {
      return true;
    }
    std::sort(hand.begin(), hand.end());
    List* start(nullptr);
    List* last(nullptr);
    List* current(start);
    for (auto it = hand.begin(); it != hand.end(); ++it) {
      current = new List(*it);
      if (last) {
        last->next = current;
      }
      if (!start) {
        start = current;
      }
      last = current;
    }
    current = start;
    List* nextStart(nullptr);
    while (start) {  // Linked list is not empty.
      List* printCurrent(start);
      last = start;
      int lastNumber = start->val;
      current = start->next;
      for (int i = 1; i < W; i++) {
        if (current->val == lastNumber) {
          if (nextStart == nullptr) {
            nextStart = current;
          }
          if (i != W - 1 && current->next == nullptr) {
            return false;
          }
          last = current;
          if (current->next == nullptr) {
            return false;
          }
          current = current->next;
          i--;
        } else if (current->val == lastNumber + 1) {
          if (i != W - 1 && current->next == nullptr) {
            return false;
          } else if (current->next == nullptr) {
            return true;
          }
          last->next = current->next;
          current = current->next;
          // delete current;
          lastNumber++;
        } else {
          return false;
        }
      }
      if (nextStart) {
        start = nextStart;
      } else if (current) {
        start = current;
      }
      nextStart = nullptr;
    }
    return true;
  }
};