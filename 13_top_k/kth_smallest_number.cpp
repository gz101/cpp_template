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

int find(const vi& nums, int k) {
  priority_queue<int> pq;
  REP(i, 0, k) {
    pq.push(nums[i]);
  }
  REP(i, k, (int) nums.size()) {
    if (nums[i] < pq.top()) {
      pq.pop();
      pq.push(nums[i]);
    }
  }
  return pq.top();
}

int main() {
  // freopen("C:\\Users\\gabri\\Desktop\\cp\\template\\in.txt", "r", stdin);
  // freopen("C:\\Users\\gabri\\Desktop\\cp\\template\\out.txt", "w", stdout);

  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int result = find(vi{1, 5, 12, 2, 11, 5}, 3);
  cout << "Case #1: " << result << "\n";

  result = find(vi{1, 5, 12, 2, 11, 5}, 4);
  cout << "Case #2: " << result << "\n";

  result = find(vi{5, 12, 11, -1, 12}, 3);
  cout << "Case #3: " << result << "\n";
}
