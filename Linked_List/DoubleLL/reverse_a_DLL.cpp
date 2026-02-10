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


void print (Node *head){
    while(head){
        cout<<head->data<<" ";
        head=head->next;
    }
}

Node *reverse_a_DLL (Node* head){

    if(head==NULL || head->next==NULL){
        return head;
    }
    Node* last = NULL;
    Node* current = head;

    while(current !=nullptr){
        last = current -> prev;
        current->prev = current->next;
        current-> next = last;

        current = current ->prev;
    }
    return last->prev;
}


int main(){
    vector<int>arr {23,13,23,5432,5,4566,78,65,7,4565,42,52,34,1,4134,135,436,547,467,47,4576,74,3452};
    Node* head = convert_to_dll(arr);
    print(head);
    cout<<endl;

    cout<<"Reversing a Double linked list : ";
    head = reverse_a_DLL(head);
    print(head);
    cout<<endl;
    return 0;
}