//CODE

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Assume this function is implemented somewhere
ListNode* addOne(ListNode* head){
    //WE find the righmost number which is not 9 

    ListNode *temp = head;
    ListNode *rightmost = NULL;
    while(temp){
        if(temp->val !=9){
            rightmost = temp;
        }
        temp = temp->next;
    }

    
    if(rightmost==NULL){
        ListNode* newHead = new ListNode(1);
        newHead->next = head;
        while(head){
            head->val=0;
            head = head-> next;
        }
    
        return newHead;
    }
    else{
        rightmost->val +=1 ;
        ListNode* curr = rightmost->next;
        while(curr){
            curr->val = 0;
            curr=curr->next;
        }
    }
    return head;
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

    // Create number: 1 -> 9 -> 9  (199)
    ListNode* head = new ListNode(1);
    head->next = new ListNode(9);
    head->next->next = new ListNode(9);

    cout << "Original List: ";
    printList(head);

    head = addOne(head);

    cout << "After Adding 1: ";
    printList(head);

    return 0;
}

