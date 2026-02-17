//Code 
#include <bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;

    Node(int data1){
        data = data1;
        next = NULL;
    }
    Node (int data1, Node* next1){
        data = data1;
        next = next1;
    }
};

Node* even_odd_seg(Node* head){
    Node* odd = head;
    Node* even = head->next;
    Node* evenHead = even;    

    while(even != NULL && even->next != NULL){
        odd->next = odd->next->next;
        even->next = even->next->next;
        odd = odd->next;
        even = even->next;

    }
    odd->next = evenHead;
    return head;

}

Node* convert_to_ll(vector<int> arr){
    Node* head = new Node (arr[0]);
    Node* mover = head;

    for(int i =1;i<arr.size();i++){
        Node* temp = new Node (arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}
void print (Node *head){
    while(head){
        cout<<head->data<<" ";
        head = head->next;
    }
}
int main(){
    vector<int> arr = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
    Node* head = convert_to_ll(arr);
    head = even_odd_seg(head);
    print(head);

    return 0;
}