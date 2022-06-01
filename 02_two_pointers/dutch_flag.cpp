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

void dutch_sort(vi& arr) {
  int lo = 0, hi = arr.size() - 1;
  for (int i = 0; i < hi + 1;) {
    if (arr[i] == 0) {
      swap(arr, i, lo);
      ++lo;
      ++i;
    } else if (arr[i] == 1) {
      ++i;
    } else {
      swap(arr, hi, i);
      --hi;
    }
  }
}

int main() {
  // freopen("C:\\Users\\gabri\\Desktop\\cp\\template\\in.txt", "r", stdin);
  // freopen("C:\\Users\\gabri\\Desktop\\cp\\template\\out.txt", "w", stdout);

  ios::sync_with_stdio(0);
  cin.tie(0);
  
  vi arr = {1, 0, 2, 1, 0};
  dutch_sort(arr);
  for (int num : arr) {
    cout << num << " ";
  }
  cout << "\n";

  arr = vi{2, 2, 0, 1, 2, 0};
  dutch_sort(arr);
  for (int num : arr) {
    cout << num << " ";
  }
  cout << "\n";
}
