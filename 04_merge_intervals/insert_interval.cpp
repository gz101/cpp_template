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

vector<pi> insert(vector<pi>& intervals, pi new_interval) {
  int n = intervals.size();
  if (intervals.empty()) {
    return vector<pi>{new_interval};
  }
  vector<pi> merged_intervals;
  int i = 0;
  while (i < n && intervals[i].S < new_interval.F) {
    merged_intervals.PB(intervals[i++]);
  }
  while (i < n && intervals[i].F <= new_interval.S) {
    new_interval.F = min(intervals[i].F, new_interval.F);
    new_interval.S = max(intervals[i].S, new_interval.S);
    ++i;
  }
  merged_intervals.PB(new_interval);
  while (i < n) {
    merged_intervals.PB(intervals[i++]);
  }
  return merged_intervals;
}

int main() {
  // freopen("C:\\Users\\gabri\\Desktop\\cp\\template\\in.txt", "r", stdin);
  // freopen("C:\\Users\\gabri\\Desktop\\cp\\template\\out.txt", "w", stdout);

  ios::sync_with_stdio(0);
  cin.tie(0);

  vector<pi> input = {{1, 3}, {5, 7}, {8, 12}};
  cout << "Case #1: ";
  for (auto interval : insert(input, {4, 6})) {
    cout << "[" << interval.F << "," << interval.S << "]";
  }
  cout << "\n";

  cout << "Case #2: ";
  for (auto interval : insert(input, {4, 10})) {
    cout << "[" << interval.F << "," << interval.S << "]";
  }
  cout << "\n";

  input = {{2, 3}, {5, 7}};
  cout << "Case #3: ";
  for (auto interval : insert(input, {1, 4})) {
    cout << "[" << interval.F << "," << interval.S << "]";
  }
  cout << "\n";
}
