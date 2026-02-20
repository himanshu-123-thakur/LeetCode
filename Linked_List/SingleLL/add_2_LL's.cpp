//CODE

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

    //WE WILL HAVE A CARRY AND A REMAINDER 
    //WE WILL START W DUMMY NIDE AND START
    
}

void printList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {

    // First number: 293
    ListNode* l1 = new ListNode(2);
    l1->next = new ListNode(9)
    l1->next->next = new ListNode(3);

    // Second number: 964
    ListNode* l2 = new ListNode(9);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);

    cout << "List1: ";
    printList(l1);

    cout << "List2: ";
    printList(l2);

    ListNode* result = addTwoNumbers(l1, l2);

    cout << "Sum: ";
    printList(result);

    return 0;
}
