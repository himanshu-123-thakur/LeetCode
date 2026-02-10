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


Node* deleteHead(Node *head){
    if(head==nullptr||head->next==nullptr){
        return NULL;
    }
    Node *temp = head;
    head = head->next;
    delete temp;
    head->prev=nullptr;

    return head;
}

Node* deleteTail(Node *head){
    if(head==nullptr){
        return NULL;
    }
    if(head->next==nullptr){
        return NULL;
    }

    Node* temp = head;
    while(temp->next!=nullptr){
        // Node *abra = temp ->next;
        // delete abra;
        // temp->next=nullptr;
        temp= temp->next;
        
    }
    Node *prevNode = temp->prev;
    prevNode->next = nullptr;

    delete temp;
    return head;
}

Node* deleteKth (Node *head,int k){
    Node *temp = head;
    if (head==nullptr || k<=0){
        return nullptr;
    }
    // if(k==1){
    //     head = head->next;
    //     delete temp;
    //     return head;
    // }

    int count = 0;
    while(temp != nullptr){
        count++;
        if(count==k)break;
        else{
            temp = temp->next;
        }
    }

    Node *prevN = temp->prev;
    Node *nextN = temp->next;

    if(prevN == nullptr && nextN == nullptr){
        delete temp;
        return nullptr;
    }
    else if(prevN == nullptr){

        return deleteHead(head);

    }
    else if(nextN==nullptr){
        return deleteTail(head);
    }
    else{
        prevN->next = temp->next;
        nextN->prev= temp->prev;
        temp->next=nullptr;
        temp->prev=nullptr;
        delete temp;
    }
    return head;
}

int main(){
    vector<int> arr = {312,32,312,32,3,13,213,24,325,45,346,7,876,8689689,6,4,35,423,523,4,34};

    Node *head=convert_to_dll(arr);
    Node *temp_1=head;
    print(head);
    cout<<endl;

    cout<<"Deleting 1st Element : ";
    head=deleteHead(head);
    print (head);
    cout<<endl;

    cout<<"Deleting last : ";
    head = deleteTail(head);
    print(head);
    cout<<endl;



    // Delete 1st element using deleteKth
        cout << "After Deleting 1st Element (using deleteKth): ";
        head = deleteKth(head, 1);
        print(head);
        cout << endl;
    
    // Delete last element using deleteKth
        cout << "After Deleting Last Element (using deleteKth): ";
        head = deleteKth(head, 10);  // if k > length, nothing happens
        print(head);
        cout << endl;

    return 0;
}