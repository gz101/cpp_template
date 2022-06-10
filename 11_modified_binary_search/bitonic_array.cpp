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

int find(const vi& arr) {
  int start = 0, end = arr.size() - 1;
  while (start < end) {
    int mid = start + (end - start) / 2;
    if (arr[mid] > arr[mid + 1]) {
      end = mid;
    } else {
      start = mid + 1;
    }
  }
  return arr[start];
}

int main() {
  // freopen("C:\\Users\\gabri\\Desktop\\cp\\template\\in.txt", "r", stdin);
  // freopen("C:\\Users\\gabri\\Desktop\\cp\\template\\out.txt", "w", stdout);

  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cout << find(vi{1, 3, 8, 12, 4, 2}) << "\n";
  cout << find(vi{3, 8, 3, 1}) << "\n";
  cout << find(vi{1, 3, 8, 12}) << "\n";
  cout << find(vi{10, 9, 8}) << "\n";
}
