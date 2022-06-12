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

struct compare {
  bool operator() (const pi& x, const pi& y) { return x.S > y.S; }
};

int find(const vi& nums, int k) {
  int distinct = 0;
  if ((int) nums.size() <= k) {
    return distinct;
  }
  unordered_map<int, int> map;
  for (auto i : nums) {
    ++map[i];
  }
  priority_queue<pi, vector<pi>, compare> pq;
  for (auto entry : map) {
    if (entry.S == 1) {
      ++distinct;
    } else {
      pq.push(entry);
    }
  }
  while (k > 0 && !pq.empty()) {
    auto entry = pq.top();
    pq.pop();
    k -= entry.S - 1;
    if (k >= 0) {
      ++distinct;
    }
  }
  if (k > 0) {
    distinct -= k;
  }
  return distinct;
}

int main() {
  // freopen("C:\\Users\\gabri\\Desktop\\cp\\template\\in.txt", "r", stdin);
  // freopen("C:\\Users\\gabri\\Desktop\\cp\\template\\out.txt", "w", stdout);

  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int result = find(vi{7, 3, 5, 8, 5, 3, 3}, 2);
  cout << "Case #1: " << result << "\n";

  result = find(vi{3, 5, 12, 11, 12}, 3);
  cout << "Case #2: " << result << "\n";

  result = find(vi{1, 2, 3, 3, 3, 3, 4, 4, 5, 5, 5}, 2);
  cout << "Case #3: " << result << "\n";
}
