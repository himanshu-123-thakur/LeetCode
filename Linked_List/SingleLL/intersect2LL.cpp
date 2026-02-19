//code
#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// DO NOT IMPLEMENT HERE
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB){
    //LET's find the Collision point first
    //for that we have to find size of each LL
    //the longer LL we will move (linger - small size ) to find colision point
    //then we start comparing from start in small LLL and colision point in big LL
    //once we find we return it


    if (!headA || !headB) return NULL;

    // 1) Find lengths
    int lenA = 0, lenB = 0;
    ListNode *a = headA, *b = headB;

    while (a) { lenA++; a = a->next; }
    while (b) { lenB++; b = b->next; }

    
    a = headA; 
    b = headB;
    int diff = abs(lenA - lenB);

    if (lenA > lenB) {
        while (diff--) a = a->next;
    } else {
        while (diff--) b = b->next;
    }

   
    while (a && b) {
        if (a == b) return a;
        a = a->next;
        b = b->next;
    }

    return NULL;
}

int main() {

    // Create common intersection part
    ListNode* common = new ListNode(8);
    common->next = new ListNode(10);
    common->next->next = new ListNode(12);

    // List A: 1 -> 2 -> 3 -> 8 -> 10 -> 12
    ListNode* headA = new ListNode(1);
    headA->next = new ListNode(2);
    headA->next->next = new ListNode(3);
    headA->next->next->next = common;

    // List B: 4 -> 5 -> 8 -> 10 -> 12
    ListNode* headB = new ListNode(4);
    headB->next = new ListNode(5);
    headB->next->next = common;

    ListNode* ans = getIntersectionNode(headA, headB);

    if (ans)
        cout << "Intersection at node value: " << ans->val << endl;
    else
        cout << "No intersection" << endl;

    return 0;
}
