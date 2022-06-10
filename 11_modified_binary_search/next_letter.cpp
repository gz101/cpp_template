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

char search(const vector<char>& arr, char key) {
  int N = arr.size();
  int start = 0, end = N - 1;
  while (start <= end) {
    int mid = start + (end - start) / 2;
    if (arr[mid] <= key) {
      start = mid + 1;
    } else {
      end = mid - 1;
    }
  }
  return arr[start % N];
}

int main() {
  // freopen("C:\\Users\\gabri\\Desktop\\cp\\template\\in.txt", "r", stdin);
  // freopen("C:\\Users\\gabri\\Desktop\\cp\\template\\out.txt", "w", stdout);

  ios::sync_with_stdio(0);
  cin.tie(0);

  cout << search(vector<char>{'a', 'c', 'f', 'h'}, 'f') << "\n";
  cout << search(vector<char>{'a', 'c', 'f', 'h'}, 'b') << "\n";
  cout << search(vector<char>{'a', 'c', 'f', 'h'}, 'm') << "\n";
  cout << search(vector<char>{'a', 'c', 'f', 'h'}, 'h') << "\n"; 
}
