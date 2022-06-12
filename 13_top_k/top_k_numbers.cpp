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

vi find(const vi& nums, int k) {
  priority_queue<int, vi, greater<int> > pq;
  REP(i, 0, k) {
    pq.push(nums[i]);
  }
  REP(i, k, (int) nums.size()) {
    if (nums[i] > pq.top()) {
      pq.pop();
      pq.push(nums[i]);
    }
  }
  vi result;
  while (!pq.empty()) {
    result.PB(pq.top());
    pq.pop();
  }
  return result;
}

int main() {
  // freopen("C:\\Users\\gabri\\Desktop\\cp\\template\\in.txt", "r", stdin);
  // freopen("C:\\Users\\gabri\\Desktop\\cp\\template\\out.txt", "w", stdout);

  ios::sync_with_stdio(0);
  cin.tie(0);
  
  vi result = find(vi{3, 1, 5, 12, 2, 11}, 3);
  cout << "Case #1: ";
  for (int num : result) {
    cout << num << " ";
  }
  cout << "\n";

  result = find(vi{5, 12, 11, -1, 12}, 3);
  cout << "Case #2: ";
  for (int num : result) {
    cout << num << " ";
  }
  cout << "\n";
}
