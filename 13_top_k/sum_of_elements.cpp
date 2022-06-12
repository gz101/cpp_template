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

int find(const vi& nums, int k1, int k2) {
  priority_queue<int, vi, greater<int>> pq;
  REP(i, 0, (int) nums.size()) {
    pq.push(nums[i]);
  }
  REP(i, 0, k1) {
    pq.pop();
  }
  int sum = 0;
  REP(i, 0, k2 - k1 - 1) {
    sum += pq.top();
    pq.pop();
  }
  return sum;
}

int main() {
  // freopen("C:\\Users\\gabri\\Desktop\\cp\\template\\in.txt", "r", stdin);
  // freopen("C:\\Users\\gabri\\Desktop\\cp\\template\\out.txt", "w", stdout);

  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int result = find(vi{1, 3, 12, 5, 15, 11}, 3, 6);
  cout << "Case #1: " << result << "\n";

  result = find(vi{3, 5, 8, 7}, 1, 4);
  cout << "Case #2: " << result << "\n";
}
