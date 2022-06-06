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

vector<double> find_level_averages(TreeNode* root) {
  vector<double> result;
  if (root == nullptr) {
    return result;
  }
  queue<TreeNode*> q;
  q.push(root);
  while (!q.empty()) {
    int level_size = q.size();
    double level_sum = 0;
    REP(i, 0, level_size) {
      TreeNode* curr = q.front();
      q.pop();
      level_sum += curr->val;
      if (curr->left != nullptr) {
        q.push(curr->left);
      }
      if (curr->right != nullptr) {
        q.push(curr->right);
      }
    }
    result.PB(level_sum / level_size);
  }
  return result;
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
  root->left->right = new TreeNode(2);
  root->right->left = new TreeNode(10);
  root->right->right = new TreeNode(5);

  vector<double> result = find_level_averages(root);
  cout << "Case #1: ";
  for (auto num : result) {
    cout << num << " ";
  }
  cout << "\n";
}
