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

vi make_squares(const vi& arr) {
  int n = arr.size();
  vi squares(n);
  int squares_curr = n - 1; // populate squares arr from the back
  int left = 0, right = n - 1;
  while (left <= right) {
    int left_value = arr[left] * arr[left];
    int right_value = arr[right] * arr[right];
    if (left_value > right_value) {
      squares[squares_curr--] = left_value;
      ++left;
    } else {
      squares[squares_curr--] = right_value;
      --right;
    }
  }
  return squares;
}

int main() {
  // freopen("C:\\Users\\gabri\\Desktop\\cp\\template\\in.txt", "r", stdin);
  // freopen("C:\\Users\\gabri\\Desktop\\cp\\template\\out.txt", "w", stdout);

  ios::sync_with_stdio(0);
  cin.tie(0);

  vi result = make_squares(vi{-2, -1, 0, 2, 3});
  for (auto num : result) {
    cout << num << " ";
  }
  cout << "\n";

  result = make_squares(vi{-3, -1, 0, 1, 2});
  for (auto num : result) {
    cout << num << " ";
  }
  cout << "\n";
}
