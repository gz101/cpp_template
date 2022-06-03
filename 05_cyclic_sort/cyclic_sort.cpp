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

void sort(vi& arr) {
  int i = 0;
  int N = arr.size();
  while (i < N) {
    int j = arr[i] - 1;
    if (arr[i] != arr[j]) {
      swap(arr, i, j);
    } else {
      ++i;
    }
  }
}

int main() {
  // freopen("C:\\Users\\gabri\\Desktop\\cp\\template\\in.txt", "r", stdin);
  // freopen("C:\\Users\\gabri\\Desktop\\cp\\template\\out.txt", "w", stdout);

  ios::sync_with_stdio(0);
  cin.tie(0);
  
  vi arr = {3, 1, 5, 4, 2};
  sort(arr);
  for (auto num : arr) {
    cout << num << " ";
  }
  cout << "\n";

  arr = vi{2, 6, 4, 3, 1, 5};
  sort(arr);
  for (auto num : arr) {
    cout << num << " ";
  }
  cout << "\n";

  arr = vi{1, 5, 6, 4, 3, 2};
  sort(arr);
  for (auto num : arr) {
    cout << num << " ";
  }
  cout << "\n";
}
