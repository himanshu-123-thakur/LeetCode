/*
REVERSE LINKED LIST IN K-GROUPS (NO DUMMY) — FULL DRY RUN + COMPLETE MAIN
Example:
1 -> 2 -> 3 -> 4 -> 5,  k = 2
Output:
2 -> 1 -> 4 -> 3 -> 5

Block notation:
[A] means node with value A
[A] -> [B] means A.next = &B

============================================================
DRY RUN (super detailed) for 1->2->3->4->5, k=2
============================================================

Initial list:
head
 |
 v
[1] -> [2] -> [3] -> [4] -> [5] -> NULL

Variables in reverseKGroup:
temp     = head = [1]
prevTail = NULL
newHead  = head = [1]

------------------------------------------------------------
ITERATION #1 (temp = [1])
------------------------------------------------------------
k_node = kthNode(temp, 2)

kthNode([1],2):
- head=[1], k=2
- while(head && --k):
    --k => 1 (true), head=head->next => head=[2]
- while(head && --k):
    --k => 0 (false) stop
return head=[2]
So k_node = [2]

Diagram:
temp -> [1] -> [2] -> [3] -> [4] -> [5] -> NULL
          ^      ^
        temp   k_node

front = k_node->next = [3]
CUT: k_node->next = NULL  => [2]->next = NULL

Now split:
Group (to reverse): temp -> [1] -> [2] -> NULL
Remainder:          front-> [3] -> [4] -> [5] -> NULL

Reverse group: revHead = reverse(temp) = reverse([1]->[2]->NULL)

reverse():
prev=NULL, cur=[1]

Step A:
nxt=cur->next=[2]
cur->next=prev => [1]->next=NULL
prev=[1]
cur=[2]

Step B:
nxt=cur->next=NULL
cur->next=prev => [2]->next=[1]
prev=[2]
cur=NULL stop

Return prev => revHead=[2]
Reversed group: [2] -> [1] -> NULL

Connect:
(temp == head)? yes ([1]==[1])
=> newHead = revHead = [2]

Update tails:
prevTail = temp  (temp was [1], now tail after reverse)
temp     = front = [3]

Current built chain:
newHead -> [2] -> [1] -> NULL
prevTail = [1]
temp -> [3] -> [4] -> [5] -> NULL

------------------------------------------------------------
ITERATION #2 (temp = [3])
------------------------------------------------------------
k_node = kthNode([3],2) => [4]
front  = [5]
CUT: [4]->next = NULL

Split:
Group:     [3] -> [4] -> NULL
Remainder: [5] -> NULL

Reverse group:
reverse([3]->[4]->NULL) => revHead=[4]->[3]->NULL

Connect:
(temp == head)? no ([3]!=[1])
=> prevTail->next = revHead
prevTail is [1]
So [1]->next = [4]

Now chain:
newHead -> [2] -> [1] -> [4] -> [3] -> NULL

Update tails:
prevTail = temp = [3]
temp     = front= [5]

------------------------------------------------------------
ITERATION #3 (temp = [5])
------------------------------------------------------------
k_node = kthNode([5],2) => NULL (not enough nodes)

if(!k_node):
  if(prevTail) prevTail->next = temp
prevTail=[3], temp=[5]
=> [3]->next = [5]
break

Final:
newHead -> [2] -> [1] -> [4] -> [3] -> [5] -> NULL

============================================================
DONE
============================================================

Important correctness note:
reverse() must return head for 0/1 node, NOT NULL.
*/

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next1) : val(x), next(next1) {}
};

class Solution {
public:
    ListNode* kthNode(ListNode* head, int k) {
        while (head && --k) head = head->next;
        return head;
    }

    ListNode* reverse(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;
        ListNode* prev = NULL;
        ListNode* cur = head;
        while (cur) {
            ListNode* nxt = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nxt;
        }
        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;

        ListNode* temp = head;
        ListNode* prevTail = NULL;
        ListNode* newHead = head;

        while (temp) {
            ListNode* k_node = kthNode(temp, k);

            if (!k_node) {
                if (prevTail) prevTail->next = temp;
                break;
            }

            ListNode* front = k_node->next;
            k_node->next = NULL;

            ListNode* revHead = reverse(temp);

            if (temp == head) newHead = revHead;
            else prevTail->next = revHead;

            prevTail = temp;
            temp = front;
        }

        return newHead;
    }
};

static ListNode* buildList(const vector<int>& a) {
    if (a.empty()) return nullptr;
    ListNode* head = new ListNode(a[0]);
    ListNode* cur = head;
    for (size_t i = 1; i < a.size(); i++) {
        cur->next = new ListNode(a[i]);
        cur = cur->next;
    }
    return head;
}

static void printList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << " -> NULL\n";
}

static void freeList(ListNode* head) {
    while (head) {
        ListNode* nxt = head->next;
        delete head;
        head = nxt;
    }
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    int k = 2;

    ListNode* head = buildList(arr);

    cout << "Original: ";
    printList(head);

    Solution s;
    ListNode* ans = s.reverseKGroup(head, k);

    cout << "Reversed in k-groups (k=" << k << "): ";
    printList(ans);

    freeList(ans);
    return 0;
}