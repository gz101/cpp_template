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

vector<vi> find_subsets(const vi& nums) {
  vector<vi> subsets;
  subsets.PB(vi());
  for (int curr : nums) {
    int N = subsets.size();
    REP(i, 0, N) {
      vi set(subsets[i]);
      set.PB(curr);
      subsets.PB(set);
    }
  }
  return subsets;
}

int main() {
  // freopen("C:\\Users\\gabri\\Desktop\\cp\\template\\in.txt", "r", stdin);
  // freopen("C:\\Users\\gabri\\Desktop\\cp\\template\\out.txt", "w", stdout);

  ios::sync_with_stdio(0);
  cin.tie(0);
  
  vector<vi> result = find_subsets(vi{1, 3});
  cout << "Case #1: " << "\n";
  for (vi& vec : result) {
    for (int num : vec) {
      cout << num << " ";
    }
    cout << "\n";
  }

  result = find_subsets(vi{1, 5, 3});
  cout << "Case #2: " << "\n";
  for (vi& vec : result) {
    for (int num : vec) {
      cout << num << " ";
    }
    cout << "\n";
  }
}
