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
  bool operator() (const pair<int, pi>& x, const pair<int, pi>& y) {
    return x.F > y.F;
  }
};

int find(const vector<vi>& lists, int k) {
  priority_queue<pair<int, pi>, vector<pair<int, pi>>, compare> pq;
  REP(i, 0, (int) lists.size()) {
    if (!lists[i].empty()) {
      pq.push(MP(lists[i][0], MP(i, 0)));
    }
  }
  int count = 0, result = 0;
  while (!pq.empty()) {
    auto node = pq.top();
    pq.pop();
    result = node.F;
    if (++count == k) {
      break;
    }
    ++node.S.S;
    if ((int) lists[node.S.F].size() > node.S.S) {
      node.F = lists[node.S.F][node.S.S];
      pq.push(node);
    }
  }
  return result;
}

int main() {
  // freopen("C:\\Users\\gabri\\Desktop\\cp\\template\\in.txt", "r", stdin);
  // freopen("C:\\Users\\gabri\\Desktop\\cp\\template\\out.txt", "w", stdout);

  ios::sync_with_stdio(0);
  cin.tie(0);
  
  vector<vi> lists = {{2, 6, 8}, {3, 6, 7}, {1, 3, 4}};
  int result = find(lists, 5);
  cout << "Case #1: " << result << "\n";
}
