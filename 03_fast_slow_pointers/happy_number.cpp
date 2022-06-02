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

int find_square_sum(int num) {
  int sum = 0;
  int digit;
  while (num > 0) {
    digit = num % 10;
    sum += digit * digit;
    num /= 10;
  }
  return sum;
}

bool find(int num) {
  int slow = num, fast = num;
  do {
    slow = find_square_sum(slow);
    fast = find_square_sum(find_square_sum(fast));
  } while (slow != fast);
  return slow == 1;
}

int main() {
  // freopen("C:\\Users\\gabri\\Desktop\\cp\\template\\in.txt", "r", stdin);
  // freopen("C:\\Users\\gabri\\Desktop\\cp\\template\\out.txt", "w", stdout);

  ios::sync_with_stdio(0);
  cin.tie(0);

  cout << find(23) << "\n";
  cout << find(12) << "\n";
}
