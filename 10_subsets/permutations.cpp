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

vector<vi> find_permutations(const vi& nums) {
  vector<vi> result;
  queue<vi> permutations;
  permutations.push(vi());
  for (int num : nums) {
    int N = permutations.size();
    REP(i, 0, N) {
      vi old = permutations.front();
      permutations.pop();
      REP(j, 0, (int) old.size() + 1) {
        vi new_permutation(old);
        new_permutation.insert(new_permutation.begin() + j, num);
        if (new_permutation.size() == nums.size()) {
          result.PB(new_permutation);
        } else {
          permutations.push(new_permutation);
        }
      }
    }
  }
  return result;
}

int main() {
  // freopen("C:\\Users\\gabri\\Desktop\\cp\\template\\in.txt", "r", stdin);
  // freopen("C:\\Users\\gabri\\Desktop\\cp\\template\\out.txt", "w", stdout);

  ios::sync_with_stdio(0);
  cin.tie(0);
  
  vector<vi> result = find_permutations(vi{1, 3, 5});
  cout << "Case #1: " << "\n";
  for (vi& vec : result) {
    for (int num : vec) {
      cout << num << " ";
    }
    cout << "\n";
  }
}
