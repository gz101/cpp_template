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
    next = nullptr;
  }
};

ListNode* reverse(ListNode* head, int k) {
  if (k <= 1 || head == nullptr) {
    return head;
  }
  ListNode* curr = head;
  ListNode* prev = nullptr;
  while (true) {
    ListNode* prefix = prev;
    ListNode* end_of_sublist = curr;
    ListNode* next = nullptr;
    for (int i = 0; curr != nullptr && i < k; ++i) {
      next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next;
    }
    if (prefix != nullptr) {
      prefix->next = prev;
    } else {
      head = prev;
    }
    end_of_sublist->next = curr;
    if (curr == nullptr) {
      break;
    }
    prev = end_of_sublist;
  }
  return head;
}

int main() {
  // freopen("C:\\Users\\gabri\\Desktop\\cp\\template\\in.txt", "r", stdin);
  // freopen("C:\\Users\\gabri\\Desktop\\cp\\template\\out.txt", "w", stdout);

  ios::sync_with_stdio(0);
  cin.tie(0);

  ListNode *head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(4);
  head->next->next->next->next = new ListNode(5);
  head->next->next->next->next->next = new ListNode(6);
  head->next->next->next->next->next->next = new ListNode(7);
  head->next->next->next->next->next->next->next = new ListNode(8);

  ListNode* result = reverse(head, 3);
  cout << "Case #1: ";
  while (result != nullptr) {
    cout << result->value << " ";
    result = result->next;
  }
  cout << "\n";
}
