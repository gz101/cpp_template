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

int search(const vi& arr, int key) {
  int start = 0, end = arr.size() - 1;
  bool is_ascend = arr[start] < arr[end];
  while (start <= end) {
    int mid = start + (end - start) / 2;
    if (key == arr[mid]) {
      return mid;
    }
    if (is_ascend) {
      if (key < arr[mid]) {
        end = mid - 1;
      } else {
        start = mid + 1;
      }
    } else {
      if (key < arr[mid]) {
        start = mid + 1;
      } else {
        end = mid - 1;
      }
    }
  }
  return -1;
}

int main() {
  // freopen("C:\\Users\\gabri\\Desktop\\cp\\template\\in.txt", "r", stdin);
  // freopen("C:\\Users\\gabri\\Desktop\\cp\\template\\out.txt", "w", stdout);

  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cout << search(vi{4, 6, 10}, 10) << "\n";
  cout << search(vi{1, 2, 3, 4, 5, 6, 7}, 5) << "\n";
  cout << search(vi{10, 6, 4}, 10) << "\n";
  cout << search(vi{10, 6, 4}, 4) << "\n";
}
