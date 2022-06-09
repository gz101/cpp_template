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

vector<string> find_permutations(const string& str) {
  vector<string> permutations;
  if (str == "") {
    return permutations;
  }
  permutations.PB(str);
  int N = str.length();
  REP(i, 0, N) {
    if (isalpha(str[i])) {
      int n = permutations.size();
      REP(j, 0, n) {
        vector<char> chs(permutations[j].begin(), permutations[j].end());
        if (isupper(chs[i])) {
          chs[i] = tolower(chs[i]);
        } else {
          chs[i] = toupper(chs[i]);
        }
        permutations.PB(string(chs.begin(), chs.end()));
      }
    }
  }
  return permutations;
}

int main() {
  // freopen("C:\\Users\\gabri\\Desktop\\cp\\template\\in.txt", "r", stdin);
  // freopen("C:\\Users\\gabri\\Desktop\\cp\\template\\out.txt", "w", stdout);

  ios::sync_with_stdio(0);
  cin.tie(0);
  
  vector<string> result = find_permutations("ad52");
  cout << "Case #1: ";
  for (auto str : result) {
    cout << str << " ";
  }
  cout << "\n";

  result = find_permutations("ab7c");
  cout << "Case #2: ";
  for (auto str : result) {
    cout << str << " ";
  }
  cout << "\n";
}
