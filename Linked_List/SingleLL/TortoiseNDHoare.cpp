//code
#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data1,Node* next1){
        data=data1;
        next=next1;
    }
    Node (int data1){
        data=data1;
        next=nullptr;
    }
};

Node* convertToLL(vector<int> arr){
    Node *head = new Node(arr[0]);
    Node *mover = head;

    for(int i =1;i<arr.size();i++){
        Node *temp =new Node (arr[i]);
        mover -> next = temp;
        mover = temp;
    }
    return head;
}

Node* tortoiseANDhoare (Node *head){
    if(head == nullptr) return nullptr;
    Node *fast = head;
    Node *slow = head;

    while(fast!=nullptr && fast->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

void print (Node *head){
    while(head){
        cout<<head->data<<" ";
        head = head->next;
    }
}

int main(){
    vector<int> arr{231,3,24,34245,34,5,346543,6,53,65,46,536,345,25,23,4134,134};
    Node *head = convertToLL(arr);
    print(head);

    cout<<endl;
    cout<<"HALO?"<<endl;
    head = tortoiseANDhoare(head);
    print(head);
    cout<<endl;


    return 0;
}