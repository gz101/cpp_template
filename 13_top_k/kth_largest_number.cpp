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

class KthLargest {
public:
  priority_queue<int, vi, greater<int>> pq;
  const int k;

  KthLargest(const vi& nums, int k) : k(k) {
    REP(i, 0, (int) nums.size()) {
      this->add(nums[i]);
    }
  }

  int add(int num) {
    this->pq.push(num);
    if ((int) pq.size() > this->k) {
      pq.pop();
    }
    return pq.top();
  }
};

int main() {
  // freopen("C:\\Users\\gabri\\Desktop\\cp\\template\\in.txt", "r", stdin);
  // freopen("C:\\Users\\gabri\\Desktop\\cp\\template\\out.txt", "w", stdout);

  ios::sync_with_stdio(0);
  cin.tie(0);
  
  KthLargest kth_largest({3, 1, 5, 12, 2, 11}, 4);
  cout << "Case #1: " << kth_largest.add(6) << "\n";
  cout << "Case #2: " << kth_largest.add(13) << "\n";
  cout << "Case #3: " << kth_largest.add(4) << "\n";
}
