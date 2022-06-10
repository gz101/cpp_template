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
  if (key > arr[arr.size() - 1]) {
    return -1;
  }
  int start = 0, end = arr.size() - 1;
  while (start <= end) {
    int mid = start + (end - start) / 2;
    if (key < arr[mid]) {
      end = mid - 1;
    } else if (key > arr[mid]) {
      start = mid + 1;
    } else {
      return mid;
    }
  }
  return start;
}

int main() {
  // freopen("C:\\Users\\gabri\\Desktop\\cp\\template\\in.txt", "r", stdin);
  // freopen("C:\\Users\\gabri\\Desktop\\cp\\template\\out.txt", "w", stdout);

  ios::sync_with_stdio(0);
  cin.tie(0);

  cout << search(vi{4, 6, 10}, 6) << "\n";
  cout << search(vi{1, 3, 8, 10, 15}, 12) << "\n";
  cout << search(vi{4, 6, 10}, 17) << "\n";
  cout << search(vi{4, 6, 10}, -1) << "\n";  
}
