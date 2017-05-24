#include <algorithm>
#include <cassert>
#include <climits>
#include <cstring>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

void PostOrder(const char* preorder,
               const char* inorder,
               const unsigned int length,
               stringstream& output) {
  if (length == 0) {
    return;
  }
  if (length == 1) {
    output << preorder[0];
    return;
  }
  int i(0);
  while (preorder[0] != inorder[i] && i < length) {
    i++;
  }
  assert(i < length);
  assert(preorder[0] == inorder[i]);
  if (i != 0) {
    PostOrder(preorder + 1, inorder, i, output);
  }
  if (i != length - 1) {
    PostOrder(preorder + 1 + i, inorder + 1 + i, length - i - 1, output);
  }
  output << preorder[0];
}

int main() {
  std::string preorder;
  std::string inorder;
  cin >> preorder;
  cin >> inorder;
  assert(preorder.size() == inorder.size());
  if (preorder.size() == 0) {
    cout << "";
    return 0;
  }
  stringstream ss;
  PostOrder(preorder.c_str(), inorder.c_str(), preorder.size(), ss);
  cout << ss.str();
}
