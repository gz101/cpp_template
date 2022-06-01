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

int remove(vi& arr, int key) {
  int next_elt = 0;
  REP(i, 0, (int) arr.size()) {
    if (arr[i] != key) {
      arr[next_elt] = arr[i];
      ++next_elt;
    }
  }
  return next_elt;
}

int main() {
  // freopen("C:\\Users\\gabri\\Desktop\\cp\\template\\in.txt", "r", stdin);
  // freopen("C:\\Users\\gabri\\Desktop\\cp\\template\\out.txt", "w", stdout);

  ios::sync_with_stdio(0);
  cin.tie(0);

  vi arr = {3, 2, 3, 6, 3, 10, 9, 3};
  cout << "Case #1: " << remove(arr, 3) << "\n";

  arr = vi {2, 11, 2, 2, 1};
  cout << "Case #2: " << remove(arr, 2) << "\n";
}
