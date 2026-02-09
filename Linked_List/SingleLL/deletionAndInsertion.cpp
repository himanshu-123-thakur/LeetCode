#include <bits/stdc++.h>
using namespace std;
class Node {
    public:
    int data;
    Node *next;

    Node(int data1,Node *node1){
        data=data1;
        next=node1;
    }
    Node(int data1){
        data=data1;
        next = nullptr;
    }
};

Node* removesHead(Node *head){
    if(head==nullptr){
        return head;
    }
    Node *temp = head;
    head = head->next;
    delete temp;
    return head;

}

Node* removeTail(Node *head){
    if(head==nullptr || head->next==nullptr){
        return NULL;
    }

    Node *temp=head;
    while(temp->next->next != nullptr){
        temp=temp->next;
    }
    delete temp->next;
    temp->next=nullptr;
    return head;
    
}

Node* removeKth(Node* head, int k) {
    if (head == nullptr || k <= 0) return head;

    if (k == 1) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    int cnt = 1;
    Node* temp = head;
    Node* prev = nullptr;

    while (temp != nullptr) {
        if (cnt == k) {
            prev->next = temp->next;  // relink
            delete temp;              // delete kth
            break;
        }
        prev = temp;
        temp = temp->next;
        cnt++;
    }
    return head; // unchanged if k > length
}

Node* removeVALUE(Node *head, int value){
    if (head == nullptr) return head;

    // if (k == 1) {
    //     Node* temp = head;
    //     head = head->next;
    //     delete temp;
    //     return head;
    // }
    Node* temp = head;
    Node* prev = nullptr;

    while (temp != nullptr) {
        if (temp->data == value) {
            prev->next = prev->next->next;  // relink
            delete temp;              // delete kth
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head; 
}

int main(){
    vector<int> arr ={42,413,41341,3413,4314,14,4,41,42,1};


    Node *head = new Node(arr[0]);
    Node *mover = head;
    for(int i =1;i<arr.size();i++){
        mover->next = new Node(arr[i]);
        mover = mover-> next;
    }

    cout<<"AFTER REMOVING HEAD"<<endl;
    head = removesHead(head);
    Node *temp = head;
    while(temp){
        cout<<temp->data<<" ";
        temp = temp->next;
    }

    cout<<endl;
    
    cout<<"AFTER REMOVING TAIL"<<endl;
    head = removeTail(head);
    Node *temp_2=head;
    while(temp_2){
        cout<<temp_2->data<<" ";
        temp_2 = temp_2->next;
    }

    cout<<endl;
    cout<<"Delete Kth element of the linked list"<<endl;
    cout<<"K = ";
    int n=0;
    cin>>n;
    head=removeKth(head,n);
    Node *temp_3=head;
    while(temp_3){
        cout<<temp_3->data<<" ";
        temp_3=temp_3->next;
    }

    cout<<endl;
    cout<<"Delete the value = ";
    int value=0;
    cin>>value;
    cout<<"AFTER DELETING "<<value <<" : ";

    head=removeVALUE(head,value);
    Node *temp_4=head;
    while(temp_4){
        cout<<temp_4->data<<" ";
        temp_4=temp_4->next;
    }

    return 0;



}