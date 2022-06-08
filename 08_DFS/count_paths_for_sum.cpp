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

  TreeNode(int val) {
    this->val = val;
    this->left = this->right = nullptr;
  }
};

int dfs(TreeNode* node, int S, vi& current_path) {
  if (node == nullptr) {
    return 0;
  }
  current_path.PB(node->val);
  int path_count = 0, path_sum = 0;
  for (auto it = current_path.rbegin(); it != current_path.rend(); ++it) {
    path_sum += *it;
    if (path_sum == S) {
      ++path_count;
    }
  }
  path_count += dfs(node->left, S, current_path);
  path_count += dfs(node->right, S, current_path);
  current_path.pop_back();
  return path_count;
}

int count_paths(TreeNode* root, int S) {
  vi current_path;
  return dfs(root, S, current_path);
}

int main() {
  // freopen("C:\\Users\\gabri\\Desktop\\cp\\template\\in.txt", "r", stdin);
  // freopen("C:\\Users\\gabri\\Desktop\\cp\\template\\out.txt", "w", stdout);

  ios::sync_with_stdio(0);
  cin.tie(0);

  TreeNode* root = new TreeNode(12);
  root->left = new TreeNode(7);
  root->right = new TreeNode(1);
  root->left->left = new TreeNode(4);
  root->right->left = new TreeNode(10);
  root->right->right = new TreeNode(5);
  cout << "Case #1: " << count_paths(root, 11) << "\n";
}
