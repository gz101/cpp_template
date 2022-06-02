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

ListNode* find_middle(ListNode* head) {
  ListNode* slow = head;
  ListNode* fast = head;
  while (fast != nullptr && fast->next != nullptr) {
    slow = slow->next;
    fast = fast->next->next;
  }
  return slow;
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
  cout << "Case #1: " << find_middle(head)->value << "\n";

  head->next->next->next->next->next = new ListNode(6);
  cout << "Case #2: " << find_middle(head)->value << "\n";

  head->next->next->next->next->next->next = new ListNode(7);
  cout << "Case #3: " << find_middle(head)->value << "\n";
}
