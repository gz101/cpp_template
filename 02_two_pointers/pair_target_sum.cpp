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

pi search(const vi& arr, int target) {
  int left = 0, right = arr.size() - 1;
  while (left < right) {
    int current_sum = arr[left] + arr[right];
    if (current_sum == target) {
      return MP(left, right);
    }
    if (target > current_sum) {
      ++left;
    } else {
      --right;
    }
  }
  return MP(-1, -1);
}

int main() {
  // freopen("C:\\Users\\gabri\\Desktop\\cp\\template\\in.txt", "r", stdin);
  // freopen("C:\\Users\\gabri\\Desktop\\cp\\template\\out.txt", "w", stdout);

  ios::sync_with_stdio(0);
  cin.tie(0);
  
  pi result = search(vi {1, 2, 3, 4, 6}, 6);
  cout << "Case #1: [" << result.F << ", " << result.S << "]" << "\n";
  result = search(vi {2, 5, 9, 11}, 11);
  cout << "Case #2: [" << result.F << ", " << result.S << "]" << "\n";
}
