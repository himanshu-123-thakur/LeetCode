//CODE 
//
//VERY COOL CONCEPT from end we dont need to know the size of LL
//FIRST take two pointers FAST SLOW move the FAST n times (n=the index you want to remove)
//Now move slow pointer and fast pointer one by one
//Now when FAST->next == NULL
//then we have reached the node one before the NODE that we want to remove
//
//
#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *n) : val(x), next(n) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // TODO: implement
        ListNode* temp =  head;
        ListNode* fast = head;
        ListNode* slow = head;

        while(n!=0){
            fast = fast->next;
            n--;
        }
                // if fast is NULL => delete head
                if(fast == NULL){
                    ListNode* del = head;
                    head = head->next;
                    delete del;
                    return head;
                }
        while(fast->next!=NULL){
            fast = fast->next;
            slow = slow -> next;
        }
        ListNode *LLDELETE = slow->next;
        slow->next = slow->next->next;
        delete(LLDELETE);

        return head;
    }
};

// ---------- helpers for local testing ----------
ListNode* buildList(const vector<int>& a) {
    ListNode* head = nullptr;
    ListNode* tail = nullptr;
    for (int x : a) {
        ListNode* node = new ListNode(x);
        if (!head) head = tail = node;
        else { tail->next = node; tail = node; }
    }
    return head;
}

void printList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << "\n";
}

void freeList(ListNode* head) {
    while (head) {
        ListNode* nxt = head->next;
        delete head;
        head = nxt;
    }
}

int main() {
    vector<int> a = {23,124,12343,54265,536356,231,24,34,414,8765,8,5,222};
    int n = 13;

    ListNode* head = buildList(a);

    Solution s;
    head = s.removeNthFromEnd(head, n);

    printList(head);
    freeList(head);
    return 0;
}
