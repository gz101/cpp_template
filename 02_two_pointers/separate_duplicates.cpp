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

int remove(vi& arr) {
  int next_non_duplicate = 1;
  REP(i, 0, (int) arr.size()) {
    // copy over i-th elt if it is distinct from prev
    if (arr[next_non_duplicate - 1] != arr[i]) {
      arr[next_non_duplicate] = arr[i];
      ++next_non_duplicate;
    }
  }
  return next_non_duplicate;
}

int main() {
  // freopen("C:\\Users\\gabri\\Desktop\\cp\\template\\in.txt", "r", stdin);
  // freopen("C:\\Users\\gabri\\Desktop\\cp\\template\\out.txt", "w", stdout);

  ios::sync_with_stdio(0);
  cin.tie(0);
  
  vi arr = {2, 3, 3, 3, 6, 9, 9};
  cout << "Case #1: " << remove(arr) << "\n";

  arr = vi {2, 2, 2, 11};
  cout << "Case #2: " << remove(arr) << "\n";
}
