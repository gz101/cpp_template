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

int search_triplet(vi& arr, int target) {
  sort(arr.begin(), arr.end());
  int smallest_diff = numeric_limits<int>::max();
  REP(i, 0, (int) arr.size() - 2) {
    int left = i + 1, right = arr.size() - 1;
    while (left < right) {
      int diff = target - arr[i] - arr[left] - arr[right];
      if (diff == 0) {
        return target;
      }
      if (abs(diff) < abs(smallest_diff) || (abs(diff) == abs(smallest_diff) && target > smallest_diff)) {
        smallest_diff = diff;
      }
      if (diff > 0) {
        ++left;
      } else {
        --right;
      }
    }
  }
  return target - smallest_diff;
}

int main() {
  // freopen("C:\\Users\\gabri\\Desktop\\cp\\template\\in.txt", "r", stdin);
  // freopen("C:\\Users\\gabri\\Desktop\\cp\\template\\out.txt", "w", stdout);

  ios::sync_with_stdio(0);
  cin.tie(0);

  vi vec = {-2, 0, 1, 2};
  cout << search_triplet(vec, 2) << "\n";
  vec = {-3, -1, 1, 2};
  cout << search_triplet(vec, 1) << "\n";
  vec = {1, 0, 1, 1};
  cout << search_triplet(vec, 100) << "\n";
}
