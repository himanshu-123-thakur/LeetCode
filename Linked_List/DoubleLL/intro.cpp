//Code
#include <bits/stdc++.h>
using namespace std;
class Node {
    public:
    int data;
    Node *next;
    Node *prev;

    Node (int data1,Node *prev1,Node *next1){
        data=data1;
        prev=prev1;
        next=next1;
    }
    // Node (int data1,Node *prev1){
    //     data=data1;
    //     prev=prev1;
    //     next=nullptr;
    // }
    // Node (int data1, Node *next1){
    //     data = data1;
    //     prev = nullptr;
    //     next = next1;
    // }
    Node (int data1){
        data = data1;
        prev = nullptr;
        next = nullptr;
    }
};

Node *convert_to_dll (vector<int> arr){
    Node *head = new Node (arr[0],nullptr,nullptr);
    Node *prevs = head;

    for(int i=1;i<arr.size();i++){
        Node *temp = new Node (arr[i],prevs,nullptr);
        prevs->next=temp;
        prevs=temp;
    }
    return head;
}

void print(Node *head){
    while(head!=nullptr){
        cout<<head->data<<" ";
        head=head->next;
    }
}

int main(){
    vector<int> arr = {312,32,312,32,3,13,213,24,325,45,346,7,876,8689689,6,4,35,423,523,4,34};

    Node *head=convert_to_dll(arr);
    Node *temp_1=head;
    print(head);
    return 0;
}