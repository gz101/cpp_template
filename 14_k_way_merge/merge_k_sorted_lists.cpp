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

struct ListNode {
  int value = 0;
  ListNode* next;

  ListNode(int value) {
    this->value = value;
    this->next = nullptr;
  }
};

struct compare {
  bool operator() (const ListNode* x, const ListNode* y) { return x->value > y->value; }
};

ListNode* merge(const vector<ListNode*>& lists) {
  priority_queue<ListNode*, vector<ListNode*>, compare> pq;
  for (auto root : lists) {
    if (root != nullptr) {
      pq.push(root);
    }
  }

  ListNode* result_head = nullptr, * result_tail = nullptr;
  while (!pq.empty()) {
    ListNode* node = pq.top();
    pq.pop();
    if (result_head == nullptr) {
      result_head = result_tail = node;
    } else {
      result_tail->next = node;
      result_tail = result_tail->next;
    }
    if (node->next != nullptr) {
      pq.push(node->next);
    }
  }
  return result_head;
}

int main() {
  // freopen("C:\\Users\\gabri\\Desktop\\cp\\template\\in.txt", "r", stdin);
  // freopen("C:\\Users\\gabri\\Desktop\\cp\\template\\out.txt", "w", stdout);

  ios::sync_with_stdio(0);
  cin.tie(0);
  
  ListNode* l1 = new ListNode(2);
  l1->next = new ListNode(6);
  l1->next->next = new ListNode(8);

  ListNode* l2 = new ListNode(3);
  l2->next = new ListNode(6);
  l2->next->next = new ListNode(7);

  ListNode* l3 = new ListNode(1);
  l3->next = new ListNode(3);
  l3->next->next = new ListNode(4);

  ListNode* result = merge(vector<ListNode*>{l1, l2, l3});
  cout << "Case #1: ";
  while (result != nullptr) {
    cout << result->value << " ";
    result = result->next;
  }
  cout << "\n";
}
