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

void find_paths_recursive(TreeNode* curr, int S, vi& current_path, vector<vi>& all_paths) {
  if (curr == nullptr) {
    return;
  }
  current_path.PB(curr->val);
  if (curr->val == S && curr->left == nullptr && curr->right == nullptr) {
    all_paths.PB(vi(current_path));
  } else {
    find_paths_recursive(curr->left, S - curr->val, current_path, all_paths);
    find_paths_recursive(curr->right, S - curr->val, current_path, all_paths);
  }
  current_path.pop_back();
}

vector<vi> find_paths(TreeNode* root, int S) {
  vector<vi> all_paths;
  vi current_path;
  find_paths_recursive(root, S, current_path, all_paths);
  return all_paths;
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
  int sum = 23;
  vector<vi> result = find_paths(root, sum);
  cout << "Case #1 (sum=" << sum << "):\n";
  for (vi vec : result) {
    for (int num : vec) {
      cout << num << " ";
    }
    cout << "\n";
  }
}
