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

class Point {
public:
  int x = 0;
  int y = 0;

  Point(int x, int y) {
    this->x = x;
    this->y = y;
  }

  int dist() const {
    return (x * x) + (y * y);
  }

  bool operator<(const Point& p) const { return p.dist() > this->dist(); }
};

vector<Point> find(const vector<Point>& points, int k) {
  priority_queue<Point> pq;
  REP(i, 0, k) {
    pq.push(points[i]);
  }
  REP(i, k, (int) points.size()) {
    if (points[i].dist() < pq.top().dist()) {
      pq.pop();
      pq.push(points[i]);
    }
  }
  vector<Point> result;
  REP(i, 0, k) {
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
  
  vector<Point> heap = find({{1, 3}, {3, 4}, {2, -1}}, 2);
  cout << "Case #1: ";
  for (auto p : heap) {
    cout << "[" << p.x << " , " << p.y << "] ";
  }
  cout << "\n";
}
