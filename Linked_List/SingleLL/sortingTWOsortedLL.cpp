//Code
#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int value;
    Node* next;
    Node (int val){
        value = val;
        next = NULL;
    }
    Node(int val, Node* next1) {
        value = val;
        next = next1;
    }
};

Node* createLL(vector<int> arr) {
    if(arr.size() == 0) return nullptr;

    Node* head = new Node(arr[0]);
    Node* mover = head;

    for(int i = 1; i < arr.size(); i++) {
        mover->next = new Node(arr[i]);
        mover = mover->next;
    }

    return head;
}

void printLL(Node* head) {
    while(head != nullptr) {
        cout << head->value << " ";
        head = head->next;
    }
    cout << endl;
}

Node* sortTwoLL(Node* head1, Node* head2) {
    
    // Your logic here

    Node* dummy = new Node (-1,nullptr);
    Node* temp1 = head1;
    Node* temp2 = head2;

    Node* temp = dummy;
    while(temp1!=NULL && temp2!=NULL){
        if(temp1->value > temp2->value){
            temp->next = temp2;
            temp = temp2;
            temp2 = temp2->next;
        }
        else{
            temp->next = temp1;
            temp = temp1;
            temp1=temp1->next;
        }
    }
    if(temp1!=NULL){
        temp ->next= temp1;
    }
    else{
        temp->next = temp2;
    }

    return dummy->next;

    
}



int main() {

    vector<int> arr1 = {1, 5, 9, 10};
    vector<int> arr2 = {2, 3, 7, 14};

    Node* head1 = createLL(arr1);
    Node* head2 = createLL(arr2);

    cout << "List 1 before sorting: ";
    printLL(head1);

    cout << "List 2 before sorting: ";
    printLL(head2);

    head1 = sortTwoLL(head1, head2);

    cout << "After sorting both lists: ";
    printLL(head1);

    return 0;
}
