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


void print (Node *head){
    while(head){
        cout<<head->data<<" ";
        head = head->next;
    }
}

Node* reverseLL (Node* head){
    //NAIVE USING STACK

        //     if (head == nullptr) return nullptr;  

    //     //Let's try
    //     stack <Node*> st ;
    //     Node* temp=head;
    //     while(temp){
    //         st.push(temp);
    //         temp = temp->next;
    //     }

    //     //Noe LIFO

    //     head = st.top();
    //     st.pop();

    //     temp = head;

    // while (st.empty()!=true) {
    //     temp->next = st.top();
    //     st.pop();
    //     temp = temp->next;
    // }

    // temp->next = nullptr;  // Important

    // return head;



    // //OTIMAL 
    
    // Node *temp = head;
    // Node *front = head;
    // Node *prev = nullptr;

    // while(temp){
    //     front = temp->next;
    //     temp->next = prev;
    //     prev = temp;
    //     temp = front;
    // }
    // return prev;


    //RECURSIVE SOLUTION

    if(head==NULL || head->next == NULL){
        return head;
    }

    
    
     Node* newHead = reverseLL(head->next);
     Node* front = head->next;
     front->next = head;
     head->next = NULL;
     return newHead;

    


}

int main(){
    vector<int> arr{231,3,24,34245,34,5,346543,6,53,65,46,536,345,25,23,4134,134};
    Node *head = convertToLL(arr);
    print(head);

    cout<<endl;
    cout<<"HALO?"<<endl;
    cout<<"REVERSE THE LINKED LIST : "<<endl;

    head = reverseLL(head);
    print(head);

    return 0;
}