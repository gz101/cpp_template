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

int search_pair(vi& arr, int target, int first) {
  int count = 0;
  int left = first + 1, right = arr.size() - 1;
  while (left < right) {
    if (arr[left] + arr[right] < target) {
      count += right - left;
      ++left;
    } else {
      --right;
    }
  }
  return count;
}

int search_triplets(vi& arr, int target) {
  sort(arr.begin(), arr.end());
  int count = 0;
  REP(i, 0, (int) arr.size() - 2) {
    count += search_pair(arr, target - arr[i], i);
  }
  return count;
}

int main() {
  // freopen("C:\\Users\\gabri\\Desktop\\cp\\template\\in.txt", "r", stdin);
  // freopen("C:\\Users\\gabri\\Desktop\\cp\\template\\out.txt", "w", stdout);

  ios::sync_with_stdio(0);
  cin.tie(0);
  
  vi vec = {-1, 0, 2, 3};
  cout << search_triplets(vec, 3) << "\n";
  vec = {-1, 4, 2, 1, 3};
  cout << search_triplets(vec, 5) << "\n";
}
