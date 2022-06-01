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

void search_pair(const vi& arr, int target, int left, vector<vi>& triplets) {
  int right = arr.size() - 1;
  while (left < right) {
    int current_sum = arr[left] + arr[right];
    if (current_sum == target) {
      triplets.PB({-target, arr[left], arr[right]});
      ++left;
      --right;
      while (left < right && arr[left] == arr[left - 1]) {
        ++left;
      }
      while (left < right && arr[right] == arr[right + 1]) {
        --right;
      }
    } else if (target > current_sum) {
      ++left;
    } else {
      --right;
    }
  }
}

vector<vi> search_triplets(vi& arr) {
  sort(arr.begin(), arr.end());
  vector<vi> triplets;
  REP(i, 0, (int) arr.size() - 2) {
    if (i > 0 && arr[i] == arr[i - 1]) {
      continue;
    }
    search_pair(arr, -arr[i], i + 1, triplets);
  }
  return triplets;
}

int main() {
  // freopen("C:\\Users\\gabri\\Desktop\\cp\\template\\in.txt", "r", stdin);
  // freopen("C:\\Users\\gabri\\Desktop\\cp\\template\\out.txt", "w", stdout);

  ios::sync_with_stdio(0);
  cin.tie(0);

  vi vec = {-3, 0, 1, 2, -1, 1, -2};
  vector<vi> result = search_triplets(vec);
  for (vi vec : result) {
    cout << "[";
    for (int num : vec) {
      cout << num << " ";
    }
    cout << "]";
  }
  cout << "\n";

  vec = {-5, 2, -1, -2, 3};
  result = search_triplets(vec);
  for (vi vec : result) {
    cout << "[";
    for (int num : vec) {
      cout << num << " ";
    }
    cout << "]";
  }
  cout << "\n";
}
