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

int connect(const vi& ropes) {
  priority_queue<int, vi, greater<int>> pq;
  REP(i, 0, (int) ropes.size()) {
    pq.push(ropes[i]);
  }
  int result = 0, temp = 0;
  while (pq.size() > 1) {
    temp = pq.top();
    pq.pop();
    temp += pq.top();
    pq.pop();
    result += temp;
    pq.push(temp);
  }
  return result;
}

int main() {
  // freopen("C:\\Users\\gabri\\Desktop\\cp\\template\\in.txt", "r", stdin);
  // freopen("C:\\Users\\gabri\\Desktop\\cp\\template\\out.txt", "w", stdout);

  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int result = connect(vi{1, 3, 11, 5});
  cout << "Case #1: " << result << "\n";
  result = connect(vi{3, 4, 5, 6});
  cout << "Case #2: " << result << "\n";
  result = connect(vi{1, 3, 11, 5, 2});
  cout << "Case #3: " << result << "\n";
}
