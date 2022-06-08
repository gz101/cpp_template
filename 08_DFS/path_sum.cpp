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

bool dfs(TreeNode* root, int S) {
  if (root == nullptr) {
    return false;
  }
  if (root->left == nullptr && root->right == nullptr) {
    return S == root->val;
  }
  int new_sum = S - root->val;
  return dfs(root->left, new_sum) || dfs(root->right, new_sum);
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
  cout << "Case #1: " << dfs(root, 23) << "\n";
  cout << "Case #2: " << dfs(root, 16) << "\n";
}
