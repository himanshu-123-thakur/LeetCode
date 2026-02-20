//Code
#include <bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node* prev;

    Node(int data1){
        data=data1;
        next=NULL;
        prev=NULL;
    }
    // Node(int data1,Node* next1){
    //     data=data1;
    //     next=next1;
    //     prev=NULL;
    // }
    // Node (int data1,Node* prev1){

    // }
    Node(int data1,Node* next1, Node* prev1){
        data=data1;
        next=next1;
        prev=prev1;
    }
};

Node* convert_to_DLL (vector<int> arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;

    for(int i=1;i<arr.size();i++){
        Node *temp = new Node(arr[i],NULL,mover);
        mover->next = temp;
        mover = mover->next;
    }
    return head;
}

void printDLL (Node* head){
    Node* temp = head;
    while(temp){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

Node* delete_key(Node* head, int key){
    Node* temp = head;
    while (temp != nullptr) {
        if (temp->data == key) {

            // If node to delete is head
            if (temp == head) {
                head = temp->next;
                if (head != nullptr)
                    head->prev = nullptr;
            } 
            else {
                temp->prev->next = temp->next;
                if (temp->next != nullptr)
                    temp->next->prev = temp->prev;
            }

            Node* nodeToDelete = temp;
            temp = temp->next;   // move first
            delete nodeToDelete; // then delete
        } 
        else {
            temp = temp->next;
        }
    }

    return head;


}

int main(){
    vector<int> arr {24,445,431,436,1423,74,96,24,96,24,312,7585,24};
    Node* head = convert_to_DLL(arr);
    printDLL(head);
    head = delete_key(head,24);
    cout<<endl;
    printDLL(head);
    return 0;
}