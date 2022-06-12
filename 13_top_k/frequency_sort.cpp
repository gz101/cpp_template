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

struct value_compare {
  bool operator() (const pair<char, int>& x, const pair<char, int>& y) {
    return y.S > x.S;
  }
};

string sort(const string& str) {
  unordered_map<char, int> map;
  for (char chr : str) {
    ++map[chr];
  }
  priority_queue<pair<char, int>, vector<pair<char, int>>, value_compare> pq;
  for (auto entry : map) {
    pq.push(entry);
  }
  string sorted_string = "";
  while (!pq.empty()) {
    auto entry = pq.top();
    pq.pop();
    REP(i, 0, entry.S) {
      sorted_string += entry.F;
    }
  }
  return sorted_string;
}

int main() {
  // freopen("C:\\Users\\gabri\\Desktop\\cp\\template\\in.txt", "r", stdin);
  // freopen("C:\\Users\\gabri\\Desktop\\cp\\template\\out.txt", "w", stdout);

  ios::sync_with_stdio(0);
  cin.tie(0);
  
  string result = sort("Programming");
  cout << "Case #1: " << result << "\n";

  result = sort("abcbab");
  cout << "Case #2: " << result << "\n";
}
