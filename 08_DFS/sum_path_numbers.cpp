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

int dfs(TreeNode* curr, int sum) {
  if (curr == nullptr) {
    return false;
  }
  int value = 10 * sum + curr->val;
  if (curr->left == nullptr && curr->right == nullptr) {
    return value;
  }
  return dfs(curr->left, value) + dfs(curr->right, value);
}

int find_sum(TreeNode* root) {
  return dfs(root, 0);
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
  cout << "Case #1: " << find_sum(root) << "\n";  
}
