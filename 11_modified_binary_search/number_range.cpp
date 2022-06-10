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

int search(const vi& arr, int key, bool find_max) {
  int key_index = -1;
  int start = 0, end = arr.size() - 1;
  while (start <= end) {
    int mid = start + (end - start) / 2;
    if (key < arr[mid]) {
      end = mid - 1;
    } else if (key > arr[mid]) {
      start = mid + 1;
    } else {
      key_index = mid;
      if (find_max) {
        start = mid + 1;
      } else {
        end = mid - 1;
      }
    }
  }
  return key_index;
}

pi find_range(const vi& arr, int key) {
  pi result(-1, -1);
  result.F = search(arr, key, false);
  if (result.F != -1) {
    result.S = search(arr, key, true);
  }
  return result;
}

int main() {
  // freopen("C:\\Users\\gabri\\Desktop\\cp\\template\\in.txt", "r", stdin);
  // freopen("C:\\Users\\gabri\\Desktop\\cp\\template\\out.txt", "w", stdout);

  ios::sync_with_stdio(0);
  cin.tie(0);
  
  pi result = find_range(vi{4, 6, 6, 6, 9}, 6);
  cout << "Range: [" << result.F << ", " << result.S << "]" << "\n";
  result = find_range(vi{1, 3, 8, 10, 15}, 10);
  cout << "Range: [" << result.F << ", " << result.S << "]" << "\n";
  result = find_range(vi{1, 3, 8, 10, 15}, 12);
  cout << "Range: [" << result.F << ", " << result.S << "]" << "\n";
}
