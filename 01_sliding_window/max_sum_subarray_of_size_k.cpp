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

int max_sum_subarray(int k, const vi& arr) {
  int window_sum = 0, max_sum = 0;
  int window_start = 0;
  REP(window_end,0,(int)arr.size()) {
    window_sum += arr[window_end];
    if (window_end >= k - 1) {
      max_sum = max(max_sum, window_sum);
      window_sum -= arr[window_start];
      ++window_start;
    }
  }
  return max_sum;
}

int main() {
  // freopen("C:\\Users\\gabri\\Desktop\\cp\\template\\in.txt", "r", stdin);
  // freopen("C:\\Users\\gabri\\Desktop\\cp\\template\\out.txt", "w", stdout);

  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cout << "Case #1: " << max_sum_subarray(3, vi {2, 1, 5, 1, 3, 2}) << "\n";
  cout << "Case #2: " << max_sum_subarray(2, vi {2, 3, 4, 1, 5}) << "\n";
}
