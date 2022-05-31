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

int min_subarray(int S, const vi& arr) {
  int window_sum = 0;
  int min_length = numeric_limits<int>::max();
  int window_start = 0;
  REP(window_end,0,(int)arr.size()) {
    window_sum += arr[window_end];
    while(window_sum >= S) {
      min_length = min(min_length, window_end - window_start + 1);
      window_sum -= arr[window_start];
      ++window_start;
    }
  }
  return min_length == numeric_limits<int>::max() ? 0 : min_length;
}

int main() {
  // freopen("C:\\Users\\gabri\\Desktop\\cp\\template\\in.txt", "r", stdin);
  // freopen("C:\\Users\\gabri\\Desktop\\cp\\template\\out.txt", "w", stdout);

  ios::sync_with_stdio(0);
  cin.tie(0);

  int result = min_subarray(7, vi {2, 1, 5, 2, 3, 2});
  cout << "Case #1: " << result << "\n";
  result = min_subarray(7, vi {2, 1, 5, 2, 8});
  cout << "Case #2: " << result << "\n";
  result = min_subarray(8, vi {3, 4, 1, 1, 6});
  cout << "Case #3: " << result << "\n";
}
