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
  vi duplicates;
  REP(i, 0, N) {
    if (arr[i] != i + 1) {
      duplicates.PB(arr[i]);
    }
  }
  return duplicates;
}

int main() {
  // freopen("C:\\Users\\gabri\\Desktop\\cp\\template\\in.txt", "r", stdin);
  // freopen("C:\\Users\\gabri\\Desktop\\cp\\template\\out.txt", "w", stdout);

  ios::sync_with_stdio(0);
  cin.tie(0);

  vi v1 = {3, 4, 4, 5, 5};
  vi duplicates = find_numbers(v1);
  cout << "Case #1: ";
  for (int num : duplicates) {
    cout << num << " ";
  }
  cout << "\n";

  v1 = {5, 4, 7, 2, 3, 5, 3};
  duplicates = find_numbers(v1);
  cout << "Case #2: ";
  for (int num : duplicates) {
    cout << num << " ";
  }
  cout << "\n";
}
