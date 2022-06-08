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

bool dfs(TreeNode* node, const vi& sequence, int index) {
  if (node == nullptr) {
    return false;
  }
  if (index >= (int) sequence.size() || node->val != sequence[index]) {
    return false;
  }
  if (node->left == nullptr && node->right == nullptr && index == (int) sequence.size() - 1) {
    return true;
  }
  return dfs(node->left, sequence, index + 1) || dfs(node->right, sequence, index + 1);
}

bool find_path(TreeNode* root, const vi& sequence) {
  if (root == nullptr) {
    return sequence.empty();
  }
  return dfs(root, sequence, 0);
}

int main() {
  // freopen("C:\\Users\\gabri\\Desktop\\cp\\template\\in.txt", "r", stdin);
  // freopen("C:\\Users\\gabri\\Desktop\\cp\\template\\out.txt", "w", stdout);

  ios::sync_with_stdio(0);
  cin.tie(0);

  TreeNode* root = new TreeNode(1);
  root->left = new TreeNode(0);
  root->right = new TreeNode(1);
  root->left->left = new TreeNode(1);
  root->right->left = new TreeNode(6);
  root->right->right = new TreeNode(5);

  cout << "Case #1: " << find_path(root, vi{1, 0, 7}) << "\n";
  cout << "Case #2: " << find_path(root, vi{1, 1, 6}) << "\n";  
}
