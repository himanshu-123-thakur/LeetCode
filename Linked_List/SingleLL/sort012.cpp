//CODE
#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

// Convert vector to linked list
Node* createLL(vector<int> arr) {
    if(arr.size() == 0) return NULL;

    Node* head = new Node(arr[0]);
    Node* mover = head;

    for(int i = 1; i < arr.size(); i++) {
        mover->next = new Node(arr[i]);
        mover = mover->next;
    }

    return head;
}

// Print linked list
void printLL(Node* head) {
    while(head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}


//YOU IMPLEMENT THIS FUNCTION
Node* sort012(Node* head) {

    // Write your logic here
    Node* dummy0 = new Node(-1);
    Node* zero = dummy0;
    Node* dummy1 = new Node(-1);
    Node* one = dummy1;
    Node* dummy2 = new Node(-1);
    Node* two = dummy2;

    Node* temp = head;

    while(temp){
        if(temp->data == 0){
            dummy0->next = temp;
            dummy0 = temp;
        }
        else if(temp->data == 1){
            dummy1->next = temp;
            dummy1=temp;
        }
        else{
            dummy2->next = temp;
            dummy2=temp;
        }

        temp = temp->next;
    }

    dummy2->next = NULL;                                    // 1. terminate 2s
    dummy1->next = two->next;                               // 2. connect 1s → 2s
    dummy0->next = (one->next) ? one->next : two->next;    // 3. connect 0s → 1s or 2s

    return (zero->next) ? zero->next : (one->next) ? one->next : two->next;
}



int main() {

    vector<int> arr = {1, 0, 2, 1, 2, 0, 1, 0, 2, 1};
    
    Node* head = createLL(arr);

    cout << "Before Sorting: ";
    printLL(head);

    head = sort012(head);

    cout << "After Sorting: ";
    printLL(head);

    return 0;
}
