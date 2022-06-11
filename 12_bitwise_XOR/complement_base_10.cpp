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

int complement(int num) {
  int bit_count = 0;
  int n = num;
  while (n > 0) {
    ++bit_count;
    n = n >> 1;
  }
  int all_1s = pow(2, bit_count) - 1;
  return num ^ all_1s;
}

int main() {
  // freopen("C:\\Users\\gabri\\Desktop\\cp\\template\\in.txt", "r", stdin);
  // freopen("C:\\Users\\gabri\\Desktop\\cp\\template\\out.txt", "w", stdout);

  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cout << "Case #1: " << complement(8) << "\n";
  cout << "Case #2: " << complement(10) << "\n";
}
