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

  TreeNode(int x) {
    this->val = x;
    this->left = this->right = nullptr;
  }
};

TreeNode* find_successor(TreeNode* root, int key) {
  if (root == nullptr) {
    return nullptr;
  }
  queue<TreeNode*> q;
  q.push(root);
  while (!q.empty()) {
    TreeNode* curr = q.front();
    q.pop();
    if (curr->left != nullptr) {
      q.push(curr->left);
    }
    if (curr->right != nullptr) {
      q.push(curr->right);
    }
    if (curr->val == key) {
      break;
    }
  }
  return q.front();
}

int main() {
  // freopen("C:\\Users\\gabri\\Desktop\\cp\\template\\in.txt", "r", stdin);
  // freopen("C:\\Users\\gabri\\Desktop\\cp\\template\\out.txt", "w", stdout);

  ios::sync_with_stdio(0);
  cin.tie(0);

  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);

  TreeNode *result = find_successor(root, 3);
  if (result != nullptr) {
    cout << "Case #1: " << result->val << "\n";
  }

  root = new TreeNode(12);
  root->left = new TreeNode(7);
  root->right = new TreeNode(1);
  root->left->left = new TreeNode(9);
  root->right->left = new TreeNode(10);
  root->right->right = new TreeNode(5);
  
  result = find_successor(root, 9);
  if (result != nullptr) {
    cout << "Case #2: " << result->val << "\n";
  }
  
  result = find_successor(root, 12);
  if (result != nullptr) {
    cout << "Case #3: " << result->val << "\n";
  }
}
