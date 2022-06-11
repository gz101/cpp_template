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

vi find(vi& nums) {
  int n1xn2 = 0;
  for (int num : nums) {
    n1xn2 ^= num;
  }
  int right_most_1 = 1;
  while ((right_most_1 & n1xn2) == 0) {
    right_most_1 = right_most_1 << 1;
  }
  int num1 = 0, num2 = 0;
  for (int num : nums) {
    if ((num & right_most_1) != 0) {
      num1 ^= num;
    } else {
      num2 ^= num;
    }
  }
  return vi{num1, num2};
}

int main() {
  // freopen("C:\\Users\\gabri\\Desktop\\cp\\template\\in.txt", "r", stdin);
  // freopen("C:\\Users\\gabri\\Desktop\\cp\\template\\out.txt", "w", stdout);

  ios::sync_with_stdio(0);
  cin.tie(0);
  
  vi v1 = {1, 4, 2, 1, 3, 5, 6, 2, 3, 5};
  vi result = find(v1);
  cout << "Case #1: " << result[0] << ", " << result[1] << "\n";

  v1 = {2, 1, 3, 2};
  result = find(v1);
  cout << "Case #2: " << result[0] << ", " << result[1] << "\n";
}
