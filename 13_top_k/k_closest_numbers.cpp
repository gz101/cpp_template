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

struct compare {
  bool operator() (const pi& x, const pi& y) { return x.F > y.F; }
};

int binary_search(const vi& arr, int target) {
  int lo = 0;
  int hi = (int) arr.size() - 1;
  while (lo <= hi) {
    int mid = lo + (hi - lo) / 2;
    if (arr[mid] == target) {
      return mid;
    }
    if (arr[mid] < target) {
      lo = mid + 1;
    } else {
      hi = mid - 1;
    }
  }
  if (lo > 0) {
    return lo - 1;
  }
  return lo;
}

vi find(const vi& arr, int K, int X) {
  int index = binary_search(arr, X);
  int lo = index - K, hi = index + K;
  lo = max(lo, 0);
  hi = min(hi, (int) arr.size() - 1);
  priority_queue<pi, vector<pi>, compare> pq;
  REP(i, lo, hi + 1) {
    pq.push(MP(abs(arr[i] - X), i));
  }
  vi result;
  REP(i, 0, K) {
    result.PB(arr[pq.top().S]);
    pq.pop();
  }
  sort(result.begin(), result.end());
  return result;
}

int main() {
  // freopen("C:\\Users\\gabri\\Desktop\\cp\\template\\in.txt", "r", stdin);
  // freopen("C:\\Users\\gabri\\Desktop\\cp\\template\\out.txt", "w", stdout);

  ios::sync_with_stdio(0);
  cin.tie(0);
  
  vi result = find(vi{5, 6, 7, 8, 9}, 3, 7);
  cout << "Case #1: ";
  for (auto num : result) {
    cout << num << " ";
  }
  cout << "\n";

  result = find(vi{2, 4, 5, 6, 9}, 3, 6);
  cout << "Case #2: ";
  for (auto num : result) {
    cout << num << " ";
  }
  cout << "\n";
}
