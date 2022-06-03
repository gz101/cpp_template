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

void swap(vi& arr, int i, int j) {
  int tmp = arr[i];
  arr[i] = arr[j];
  arr[j] = tmp;
}

int find_missing(vi& arr) {
  int i = 0;
  int N = arr.size();
  while (i < N) {
    if (arr[i] < N && arr[i] != arr[arr[i]]) {
      swap(arr, i, arr[i]);
    } else {
      ++i;
    }
  }
  REP(i, 0, N) {
    if (arr[i] != i) {
      return i;
    }
  }
  return N;
}

int main() {
  // freopen("C:\\Users\\gabri\\Desktop\\cp\\template\\in.txt", "r", stdin);
  // freopen("C:\\Users\\gabri\\Desktop\\cp\\template\\out.txt", "w", stdout);

  ios::sync_with_stdio(0);
  cin.tie(0);

  vi v1 = {4, 0, 3, 1};
  cout << find_missing(v1) << "\n";
  v1 = {8, 3, 5, 2, 4, 6, 0, 1};
  cout << find_missing(v1) << "\n";  
}
