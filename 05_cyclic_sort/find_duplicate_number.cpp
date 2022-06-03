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

int find_number(vi& arr) {
  int i = 0;
  int N = arr.size();
  while (i < N) {
    if (arr[i] != i + 1) {
      if (arr[i] != arr[arr[i] - 1]) {
        swap(arr, i, arr[i] - 1);
      } else {
        return arr[i];
      }
    } else {
      ++i;
    }
  }
  return -1;
}

int main() {
  // freopen("C:\\Users\\gabri\\Desktop\\cp\\template\\in.txt", "r", stdin);
  // freopen("C:\\Users\\gabri\\Desktop\\cp\\template\\out.txt", "w", stdout);

  ios::sync_with_stdio(0);
  cin.tie(0);

  vi v1 = {1, 4, 4, 3, 2};
  cout << find_number(v1) << "\n";

  v1 = {2, 1, 3, 3, 5, 4};
  cout << find_number(v1) << "\n";

  v1 = {2, 4, 1, 4, 4};
  cout << find_number(v1) << "\n";
}
