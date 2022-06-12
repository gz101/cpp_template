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
  char operator()(const pi& x, const pi& y) { return x.S > y.S; }
};

vi find(const vi& nums, int k) {
  unordered_map<int, int> map;
  for (int n : nums) {
    ++map[n];
  }
  priority_queue<pi, vector<pi>, value_compare> pq;
  for (auto entry : map) {
    pq.push(entry);
    if ((int) pq.size() > k) {
      pq.pop();
    }
  }
  vi top;
  while (!pq.empty()) {
    top.PB(pq.top().F);
    pq.pop();
  }
  return top;
}

int main() {
  // freopen("C:\\Users\\gabri\\Desktop\\cp\\template\\in.txt", "r", stdin);
  // freopen("C:\\Users\\gabri\\Desktop\\cp\\template\\out.txt", "w", stdout);

  ios::sync_with_stdio(0);
  cin.tie(0);
  
  vi result = find(vi{1, 3, 5, 12, 11, 12, 11}, 2);
  cout << "Case #1: ";
  for (auto num : result) {
    cout << num << " ";
  }
  cout << "\n";

  result = find(vi{5, 12, 11, 3, 11}, 2);
  cout << "Case #2: ";
  for (auto num : result) {
    cout << num << " ";
  }
  cout << "\n";
}
