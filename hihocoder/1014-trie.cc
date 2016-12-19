#include <string>
#include <unordered_set>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

typedef struct Node {
  unordered_map<char, Node*> children;
  unsigned int start;
  unsigned int word;
  explicit Node() : start(0), word(0) {}
};

void Insert(const string& str, Node* const root) {
  Node* current = root;
  for (unsigned int i = 0; i < str.size(); i++) {
    char c = str[i];
    unordered_map<char, Node*>& children = current->children;
    if (children.find(c) == children.end()) {
      children[c] = new Node();
    }
    children[c]->start++;
    if (i == str.size() - 1) {
      children[c]->word++;
    }
    current = children[c];
  }
}

int Calc(const string& str, Node* const root) {
  Node* current = root;
  for (unsigned int i = 0; i <= str.size(); i++) {
    if (i == str.size()) {
      return current->start;
    }
    char c = str[i];
    unordered_map<char, Node*>& children = current->children;
    if (children.find(c) == children.end()) {
      return 0;
    } else {
      current = children[c];
    }
  }
}

int main() {
  int dict_num;
  string input;
  cin >> dict_num;
  Node* const root = new Node();
  for (int i = 0; i < dict_num; i++) {
    cin >> input;
    Insert(input, root);
  }
  int test_num;
  cin >> test_num;
  for (int i = 0; i < test_num; i++) {
    cin >> input;
    cout << Calc(input, root) << endl;
  }
}