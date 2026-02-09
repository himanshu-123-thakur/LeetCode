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

        // If head itself has the value
        if (head->data == value) {
            Node* del = head;
            head = head->next;
            delete del;
            return head;
        }

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


Node* addNode(Node *head, int value){

    Node *temp = new Node(value, head);
    return temp;

}


Node* addNodeEND(Node *head,int value){
    if(head == nullptr){
        return new Node(value);
    }
    Node *temp = head;
    while(temp->next!=nullptr){
        temp = temp-> next;
    }
    temp->next=new Node(value);
    return head;
}


Node* addNodePOS(Node *head,int value,int pos){

    if(pos <= 0) return head;              // invalid

    if(pos == 1){                          // insert at head
        return new Node(value, head);
    }


    if(head == nullptr){
        return nullptr;
    }

    Node *temp = head;
    
    for(int i=1;i<pos-1;i++){
        if(temp->next == nullptr) break;
        temp = temp->next;
    }
    Node *newNode = new Node(value,temp->next);
    temp->next = newNode;

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
    cout<<endl;

    cout<<"ADD : ";
    int value_5;
    cin>>value_5;
    cout<<"After adding "<<value_5<<" --->  ";
    head=addNode(head,value_5);
    Node *temp_5=head;
    while(temp_5){
        cout<<temp_5->data<<" ";
        temp_5=temp_5->next;
    }

    cout<<endl;
    cout<<"Add at end : ";
    int value_6;
    cin>>value_6;
    cout<<"After adding "<<value_6<<" ---> ";
    head = addNodeEND(head,value_6);

    Node *temp_6=head;
    while(temp_6){
        cout<<temp_6->data<<" ";
        temp_6=temp_6->next;
    }





    cout<<endl;
    cout<<"Add at pos : ";
    int pos =0 ;
    cin>>pos;
    int value_7;
    cin>>value_7;
    cout<<"After adding "<<value_7<<" at pos "<<pos<<" ---> ";
    head = addNodePOS(head,value_7,pos);

    Node *temp_7=head;
    while(temp_7){
        cout<<temp_7->data<<" ";
        temp_7=temp_7->next;
    }
    

    return 0;



}