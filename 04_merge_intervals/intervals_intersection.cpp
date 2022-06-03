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

vector<pi> merge(const vector<pi>& arr1, const vector<pi>& arr2) {
  vector<pi> result;
  int i = 0, j = 0;
  int len1 = arr1.size(), len2 = arr2.size();
  while (i < len1 && j < len2) {
    if ((arr1[i].F >= arr2[j].F && arr1[i].F <= arr2[j].S) ||
        (arr2[j].F >= arr1[i].F && arr2[j].F <= arr1[i].S)) {
      result.PB({max(arr1[i].F, arr2[j].F), min(arr1[i].S, arr2[j].S)});
    }
    if (arr1[i].S < arr2[j].S) {
      ++i;
    } else {
      ++j;
    }
  }
  return result;
}

int main() {
  // freopen("C:\\Users\\gabri\\Desktop\\cp\\template\\in.txt", "r", stdin);
  // freopen("C:\\Users\\gabri\\Desktop\\cp\\template\\out.txt", "w", stdout);

  ios::sync_with_stdio(0);
  cin.tie(0);

  vector<pi> input1 = {{1, 3}, {5, 6}, {7, 9}};
  vector<pi> input2 = {{2, 3}, {5, 7}};
  vector<pi> result = merge(input1, input2);
  cout << "Case #1: ";
  for (pi& interval : result) {
    cout << "[" << interval.F << "," << interval.S << "]";
  }
  cout << "\n";

  input1 = {{1, 3}, {5, 7}, {9, 12}};
  input2 = {{5, 10}};
  result = merge(input1, input2);
  cout << "Case #2: ";
  for (pi& interval : result) {
    cout << "[" << interval.F << "," << interval.S << "]";
  }
  cout << "\n";
}
