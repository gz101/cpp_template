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

class ArrayReader {
public:
  vi arr;

  ArrayReader(const vi& arr) { this->arr = arr; }

  int get(int index) {
    if (index >= (int) arr.size()) {
      return numeric_limits<int>::max();
    }
    return arr[index];
  }
};

int binary_search(ArrayReader* reader, int key, int start, int end) {
  while (start <= end) {
    int mid = start + (end - start) / 2;
    if (key < reader->get(mid)) {
      end = mid - 1;
    } else if (key > reader->get(mid)) {
      start = mid + 1;
    } else {
      return mid;
    }
  }
  return -1;
}

int search(ArrayReader* reader, int key) {
  int start = 0, end = 1;
  while (reader->get(end) < key) {
    int new_start = end + 1;
    end += (end - start + 1) * 2;
    start = new_start;
  }
  return binary_search(reader, key, start, end);
}

int main() {
  // freopen("C:\\Users\\gabri\\Desktop\\cp\\template\\in.txt", "r", stdin);
  // freopen("C:\\Users\\gabri\\Desktop\\cp\\template\\out.txt", "w", stdout);

  ios::sync_with_stdio(0);
  cin.tie(0);
  
  ArrayReader* reader =
      new ArrayReader(vi{4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30});
  cout << search(reader, 16) << "\n";
  cout << search(reader, 11) << "\n";
  reader = new ArrayReader(vi{1, 3, 8, 10, 15});
  cout << search(reader, 15) << "\n";
  cout << search(reader, 200) << "\n";
  delete reader;
}
