class ProductOfNumbers {
 public:
  int numbers[40000];
  int productOfInterval[200];  // Interval is 200.
  int index;
  ProductOfNumbers() {
    memset(numbers, 0, sizeof(numbers));
    for (int i = 0; i < 200; i++) {
      productOfInterval[i] = 1;
    }
    index = 0;
  }

  void add(int num) {
    numbers[index] = num;
    productOfInterval[index / 200] *= num;
    index++;
  }

  int getProduct(int k) {
    int answer(1);
    int maxRemain = index % 200;
    int remain = min(k, maxRemain);
    for (int i = 0; i < remain; i++) {
      if (numbers[index - i - 1] == 0) {
        return 0;
      }
      answer *= numbers[index - i - 1];
    }
    int intervals = (k - remain) / 200;
    int currentInterval = index / 200;
    for (int i = 1; i <= intervals; i++) {
      answer *= productOfInterval[currentInterval - i];
    }
    int lastRemain = k - remain - intervals * 200;
    for (int i = 0; i < lastRemain; i++) {
      int currentIndex = index - remain - intervals * 200 - i - 1;
      if (numbers[currentIndex] == 0) {
        return 0;
      }
      answer *= numbers[currentIndex];
    }
    return answer;
  }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */