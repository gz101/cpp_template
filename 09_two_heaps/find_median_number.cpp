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

class MedianOfAStream {
private:
  priority_queue<int> max_heap;
  priority_queue<int, vi, greater<int>> min_heap;

public:
  void insert_num(int num) {
    if (max_heap.empty() || max_heap.top() >= num) {
      max_heap.push(num);
    } else {
      min_heap.push(num);
    }

    if (max_heap.size() > min_heap.size() + 1) {
      min_heap.push(max_heap.top());
      max_heap.pop();
    } else if (max_heap.size() < min_heap.size()) {
      max_heap.push(min_heap.top());
      min_heap.pop();
    }
  }

  double find_median() {
    if (max_heap.size() == min_heap.size()) {
      return (max_heap.top() + min_heap.top()) / 2.0;
    }
    return max_heap.top();
  }
};

int main() {
  // freopen("C:\\Users\\gabri\\Desktop\\cp\\template\\in.txt", "r", stdin);
  // freopen("C:\\Users\\gabri\\Desktop\\cp\\template\\out.txt", "w", stdout);

  ios::sync_with_stdio(0);
  cin.tie(0);
  
  MedianOfAStream medianOfAStream;
  medianOfAStream.insert_num(3);
  medianOfAStream.insert_num(1);
  cout << "Case #1: " << medianOfAStream.find_median() << "\n";
  medianOfAStream.insert_num(5);
  cout << "Case #2: " << medianOfAStream.find_median() << "\n";
  medianOfAStream.insert_num(4);
  cout << "Case #3: " << medianOfAStream.find_median() << "\n";
}
