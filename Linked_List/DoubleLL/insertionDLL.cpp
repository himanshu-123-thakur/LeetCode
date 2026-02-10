//Code
#include <bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node *next;
    Node *prev;

    Node(int data1,Node *next1,Node *prev1){
        data = data1;
        next = next1;
        prev = prev1;
    }
    Node(int data1){
        data = data1;
        next = nullptr;
        prev = nullptr;
    }
};

Node* convert_to_dll (vector<int> arr){
    Node* head = new Node(arr[0]);
    Node* prev = head;

    for(int i=1;i<arr.size();i++){
        Node *temp = new Node (arr[i],nullptr,prev);
        prev->next=temp;
        prev=temp;
    }
    return head;

}

Node* insertionHEAD(Node *head){
    Node* temp = head;
    head = new Node (100,temp,nullptr);

    if (temp != nullptr) {
        temp->prev = head;   // ✅ IMPORTANT
    }
    
    return head;
}

void print (Node *head){
    while(head){
        cout<<head->data<<" ";
        head=head->next;
    }
}

Node* insertionEND(Node* head){
    Node* temp = head;
    while(temp->next!=nullptr){
        temp = temp->next;
    }
    Node* newEND = new Node(100, nullptr, temp);
    temp->next = newEND;

    return head;
}

Node* inserting_at_secondlast(Node* head){

    if(head->next==NULL){
        return insertionHEAD(head);
    }

    Node*tail = head;
    while(tail->next != NULL){
        tail = tail->next;
    }

    Node* previous = tail->prev;
    Node* newNode = new Node(100,tail,previous);
    previous->next = newNode;
    tail->prev = newNode;
     

    return head;
}

int main(){
    vector<int>arr {23,13,23,5432,5,4566,78,65,7,4565,42,52,34,1,4134,135,436,547,467,47,4576,74,3452};
    Node* head = convert_to_dll(arr);
    print(head);

    cout<<endl;
    cout<<"Inserting at start : ";
    head = insertionHEAD(head);
    print(head);
    cout<<endl;

    cout<<"Inserting at end : ";
    head = insertionEND(head);
    print(head);
    cout<<endl;

    cout<<"Inserting at SECOND LAST : ";
    head = inserting_at_secondlast(head);
    print(head);
    cout<<endl;



    return 0;
}