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

vi find_numbers(vi& arr) {
  int i = 0;
  int N = arr.size();
  while (i < N) {
    if (arr[i] != arr[arr[i] - 1]) {
      swap(arr, i, arr[i] - 1);
    } else {
      ++i;
    }
  }
  vi missing;
  REP(i, 0, N) {
    if (arr[i] != i + 1) {
      missing.PB(i + 1);
    }
  }
  return missing;
}

int main() {
  // freopen("C:\\Users\\gabri\\Desktop\\cp\\template\\in.txt", "r", stdin);
  // freopen("C:\\Users\\gabri\\Desktop\\cp\\template\\out.txt", "w", stdout);

  ios::sync_with_stdio(0);
  cin.tie(0);

  vi v1 = {2, 3, 1, 8, 2, 3, 5, 1};
  vi missing = find_numbers(v1);
  cout << "Case #1: ";
  for (int num : missing) {
    cout << num << " ";
  }
  cout << "\n";

  v1 = {2, 4, 1, 2};
  missing = find_numbers(v1);
  cout << "Case #2: ";
  for (int num : missing) {
    cout << num << " ";
  }
  cout << "\n";

  v1 = {2, 3, 2, 1};
  missing = find_numbers(v1);
  cout << "Case #3: ";
  for (auto num : missing) {
    cout << num << " ";
  }
  cout << "\n";
}
