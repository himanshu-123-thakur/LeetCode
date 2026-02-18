//CODE
#include <bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;

    Node(int data1,Node* next1){
        data = data1;
        next = next1;
    }
    Node (int data1){
        data=data1;
        next = NULL;
    }

};
Node* convert(vector<int> arr){
    Node *head = new Node(arr[0]);
    Node* mover = head;
    
    for(int i =1;i<arr.size();i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

void print_LL (Node* head){
    Node* temp = head;
    while(temp){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

Node* sort_two_LL (Node *head1 , Node* head2){
    Node* dummy = new Node(-1,NULL);
    Node* temp1 =head1;
    Node* temp2 = head2;
    Node *temp = dummy;

    while(temp1!=NULL && temp2!=NULL){
        if(temp1->data > temp2->data){
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

Node* sort_LL (Node* head){
    Node* temp = head;
    if(temp == NULL || temp -> next == NULL){
        return temp;
    }

    //MID POINT
    //TORTOISE and HOARE 
    Node *slow =  head;
    Node *fast = head->next;
    while(fast !=NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }

    //SLOW IS THE MID POINT;
    Node* leftHead = head;
    Node* rightHead = slow -> next;

    slow ->next = NULL;
    leftHead = sort_LL(leftHead);
    rightHead = sort_LL(rightHead);

    return sort_two_LL(leftHead,rightHead);
}

int main (){
    vector<int> arr {23,1,545,2,134,13542,531,412,44,54,76586234,13,21,3,455,75,8,565,32};
    Node* head = convert(arr);
    print_LL (head);
    cout<<endl;
    cout<<"Let's Sort this BITCH : "<<endl;
    head = sort_LL (head);
    print_LL (head);
    return 0;
}