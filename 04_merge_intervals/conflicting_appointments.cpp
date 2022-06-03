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

bool can_attend_all(vector<pi>& intervals) {
  sort(intervals.begin(), intervals.end(), [](const pi& x, const pi& y){return x.F < y.F;});
  REP(i, 1, (int) intervals.size()) {
    if (intervals[i].F < intervals[i - 1].S) {
      return false;
    }
  }
  return true;
}

int main() {
  // freopen("C:\\Users\\gabri\\Desktop\\cp\\template\\in.txt", "r", stdin);
  // freopen("C:\\Users\\gabri\\Desktop\\cp\\template\\out.txt", "w", stdout);

  ios::sync_with_stdio(0);
  cin.tie(0);

  vector<pi> intervals = {{1, 4}, {2, 5}, {7, 9}};
  bool result = can_attend_all(intervals);
  cout << "Case #1: " << result << "\n";

  intervals = {{6, 7}, {2, 4}, {8, 12}};
  result = can_attend_all(intervals);
  cout << "Case #2: " << result << "\n";

  intervals = {{4, 5}, {2, 3}, {3, 6}};
  result = can_attend_all(intervals);
  cout << "Case #3: " << result << "\n";
}
