#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pi;
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i, a, b) for (int i = a; i < b; ++i)

struct TreeNode {
  int val = 0;
  TreeNode* left;
  TreeNode* right;
  TreeNode* next;

  TreeNode(int x) {
    this->val = x;
    this->left = this->right = this->next = nullptr;
  }

  // from source code
  void printLevelOrder() {
    TreeNode* nextLevelRoot = this;
    while (nextLevelRoot != nullptr) {
      TreeNode* current = nextLevelRoot;
      nextLevelRoot = nullptr;
      while (current != nullptr) {
        cout << current->val << " ";
        if (nextLevelRoot == nullptr) {
          if (current->left != nullptr) {
            nextLevelRoot = current->left;
          } else if (current->right != nullptr) {
            nextLevelRoot = current->right;
          }
        }
        current = current->next;
      }
      cout << "\n";
    }
  }
};

void connect(TreeNode* root) {
  if (root == nullptr) {
    return;
  }
  queue<TreeNode*> q;
  q.push(root);
  while (!q.empty()) {
    TreeNode* prev = nullptr;
    int level_size = q.size();
    REP(i, 0, level_size) {
      TreeNode* curr = q.front();
      q.pop();
      if (prev != nullptr) {
        prev->next = curr;
      }
      prev = curr;
      if (curr->left != nullptr) {
        q.push(curr->left);
      }
      if (curr->right != nullptr) {
        q.push(curr->right);
      }
    }
  }
}

int main() {
  // freopen("C:\\Users\\gabri\\Desktop\\cp\\template\\in.txt", "r", stdin);
  // freopen("C:\\Users\\gabri\\Desktop\\cp\\template\\out.txt", "w", stdout);

  ios::sync_with_stdio(0);
  cin.tie(0);

  TreeNode* root = new TreeNode(12);
  root->left = new TreeNode(7);
  root->right = new TreeNode(1);
  root->left->left = new TreeNode(9);
  root->right->left = new TreeNode(10);
  root->right->right = new TreeNode(5);
  connect(root);
  cout << "Case #1: " << "\n";
  root->printLevelOrder();
}
