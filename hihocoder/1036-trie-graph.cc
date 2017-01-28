#include <string>
#include <unordered_set>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <queue>

using namespace std;

typedef struct Node {
  unordered_map<char, Node*> children;
  char value;
  Node* parent;
  Node* fail;
  bool word;  // The end of a word.
  explicit Node(char c)
      : value(c), parent(nullptr), fail(nullptr), word(false) {}
};

void Insert(const string& str, Node* const root) {
  Node* current = root;
  for (unsigned int i = 0; i < str.size(); i++) {
    char c = str[i];
    unordered_map<char, Node*>& children = current->children;
    if (children.find(c) == children.end()) {
      children[c] = new Node(c);
      children[c]->parent = current;
    }
    if (i == str.size() - 1) {
      children[c]->word = true;
    }
    current = children[c];
  }
}

void FillFail(Node* root) {
  if (root == nullptr)
    return;
  queue<Node*> waiting;
  for (auto child : root->children) {
    waiting.push(child.second);
  }
  while (!waiting.empty()) {
    Node* current = waiting.front();
    waiting.pop();
    for (auto child : current->children) {
      waiting.push(child.second);
    }
    Node* parent = current->parent;
    while (auto fail = parent->fail) {
      if (fail->children.find(current->value) == fail->children.end()) {
        parent = fail;
      } else {
        current->fail = fail->children[current->value];
        break;
      }
    }
    if (current->fail == nullptr) {
      current->fail = root;
    }
  }
  root->fail = root;
}

bool Search(const string& input, Node* root) {
  Node* current = root;
  for (int i = 0; i < input.size(); i++) {
    if (current->children.find(input[i]) != current->children.end()) {
      current = current->children[input[i]];
      if (current->word)
        return true;
    } else if (current == root) {
      continue;
    } else {
      current = current->fail;
      i--;
    }
  }
  return false;
}

int main() {
  int dict_num;
  string input;
  cin >> dict_num;
  Node* const root = new Node(' ');
  for (int i = 0; i < dict_num; i++) {
    cin >> input;
    Insert(input, root);
  }
  FillFail(root);
  cin >> input;
  if (Search(input, root)) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}
