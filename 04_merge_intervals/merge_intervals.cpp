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

vector<pi> merge(vector<pi>& arr) {
  int n = arr.size();
  if (n < 2) {
    return arr;
  }
  sort(arr.begin(), arr.end(), [](const pi& x, const pi& y) { return x.F < y.F; });
  vector<pi> merged_intervals;
  
  int start = arr[0].F;
  int end = arr[0].S; 
  REP(i, 1, n) {
    pi curr = arr[i];
    if (curr.F <= end) {
      end = max(curr.S, end);
    } else {
      merged_intervals.PB(MP(start, end));
      start = curr.F;
      end = curr.S;
    }
  }
  merged_intervals.PB(MP(start, end));
  return merged_intervals;
}

int main() {
  // freopen("C:\\Users\\gabri\\Desktop\\cp\\template\\in.txt", "r", stdin);
  // freopen("C:\\Users\\gabri\\Desktop\\cp\\template\\out.txt", "w", stdout);

  ios::sync_with_stdio(0);
  cin.tie(0);

  vector<pi> input = {{1, 3}, {2, 5}, {7, 9}};
  cout << "Case #1: ";
  vector<pi> result = merge(input);
  for (auto interval : result) {
    cout << "(" << interval.F << "," << interval.S << ")";
  }
  cout << "\n";

  input = {{6, 7}, {2, 4}, {5, 9}};
  result = merge(input);
  cout << "Case #2: ";
  for (auto interval : result) {
    cout << "(" << interval.F << "," << interval.S << ")";
  }
  cout << "\n";

  input = {{1, 4}, {2, 6}, {3, 5}};
  result = merge(input);
  cout << "Case #3: ";
  for (auto interval : result) {
    cout << "(" << interval.F << "," << interval.S << ")";
  }
  cout << "\n";
}
