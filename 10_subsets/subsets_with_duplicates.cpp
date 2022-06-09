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

vector<vi> find_subsets(vi& nums) {
  sort(nums.begin(), nums.end());
  vector<vi> subsets;
  subsets.PB(vi());
  int start = 0, end = 0;
  REP(i, 0, (int) nums.size()) {
    start = 0;
    if (i > 0 && nums[i] == nums[i - 1]) {
      start = end + 1;
    }
    end = subsets.size() - 1;
    REP(j, start, end + 1) {
      vi set(subsets[j]);
      set.PB(nums[i]);
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
  
  vi vec = {1, 3, 3};
  vector<vi> result = find_subsets(vec);
  cout << "Case #1: " << "\n";
  for (vi& vec : result) {
    for (int num : vec) {
      cout << num << " ";
    }
    cout << "\n";
  }

  vec = {1, 5, 3, 3};
  result = find_subsets(vec);
  cout << "Case #2: " << "\n";
  for (vi& vec : result) {
    for (int num : vec) {
      cout << num << " ";
    }
    cout << "\n";
  }
}
