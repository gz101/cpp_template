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

int find_length(const string& str, int k) {
  int window_start = 0;
  int max_length = 0;
  unordered_map<char, int> char_map;
  REP(window_end, 0, (int) str.length()) {
    char next_char = str[window_end];
    ++char_map[next_char];
    while ((int) char_map.size() > k) {
      char start_char = str[window_start];
      --char_map[start_char];
      if (char_map[start_char] == 0) {
        char_map.erase(start_char);
      }
      ++window_start;
    }
    max_length = max(max_length, window_end - window_start + 1);
  }
  return max_length;
}

int main() {
  // freopen("C:\\Users\\gabri\\Desktop\\cp\\template\\in.txt", "r", stdin);
  // freopen("C:\\Users\\gabri\\Desktop\\cp\\template\\out.txt", "w", stdout);

  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cout << "Case #1: " << find_length("araaci", 2) << "\n";
  cout << "Case #2: " << find_length("araaci", 1) << "\n";
  cout << "Case #3: " << find_length("cbbebi", 3) << "\n";
}
