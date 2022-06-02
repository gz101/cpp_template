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

ListNode* find_start(ListNode* head, int cycle_length) {
  ListNode* p1 = head, * p2 = head;
  while (cycle_length > 0) {
    p2 = p2->next;
    --cycle_length;
  }
  while (p1 != p2) {
    p1 = p1->next;
    p2 = p2->next;
  }
  return p1;
}

int calculate_cycle_length(ListNode* slow) {
  ListNode* curr = slow;
  int cycle_length = 0;
  do {
    curr = curr->next;
    ++cycle_length;
  } while (curr != slow);
  return cycle_length;
}

ListNode* find_cycle_start(ListNode* head) {
  int cycle_length = 0;
  ListNode* slow = head;
  ListNode* fast = head;
  while (fast != nullptr && fast->next != nullptr) {
    slow = slow->next;
    fast = fast->next->next;
    if (slow == fast) {
      cycle_length = calculate_cycle_length(slow);
      break;
    }
  }
  return find_start(slow, cycle_length);
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

  head->next->next->next->next->next->next = head->next->next;
  cout << "Case #1: " << find_cycle_start(head)->value << "\n";

  head->next->next->next->next->next->next = head->next->next->next;
  cout << "Case #2: " << find_cycle_start(head)->value << "\n";

  head->next->next->next->next->next->next = head;
  cout << "Case #3: " << find_cycle_start(head)->value << "\n";
}
