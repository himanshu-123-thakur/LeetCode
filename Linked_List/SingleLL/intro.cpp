//CODE

//INTRO TO LINKED LIST

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    public :
    
    /* data */
    int data;
    Node * next;

    Node (int data1, Node *next1){
        data=data1;
        next=next1;
    }
    Node (int data1){
        data=data1;
        next = nullptr;
    }
};

Node* convertArr2LL(int arr[]){
    //WHOLE ARRAY IN A LINKED LIST  
    //WE need a header first

    Node *head = new Node(arr[0]);
    Node *mover = head;

    for(int i=1;i<7;i++){
        Node * temp= new Node(arr[i]);
        mover->next= temp;
        mover = temp;
    }

    return head;
    
}

int lenghtofLL (Node *head){
    int count =0;
    Node *temp = head;

    while(temp){
        count++;
        temp=temp->next;
    }
    return count;
}

bool checkifPresent(Node *head,int n){
    Node *temp = head;
    while(temp){
        if(temp->data==n){
            return 1;

            break;
        }
        else{
            temp=temp->next;
        }
    }
    return 0;
}

int main(){

    int arr[7]={243,423,65,456,46,4562,465};
    // Node *start = new Node(arr[1],nullptr);

    // cout<<start<<endl;
    // cout<<start->data<<endl;
    // cout<<start->next<<endl;

    Node *head = convertArr2LL(arr);
    cout<<head->data<<endl;
    Node *temp=head;

    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
    cout<<"Count is = "<<lenghtofLL(head)<<endl;

    cout<<boolalpha;

    int n;
    cout<<"Search for = ";
    cin>>n;

    cout<<"is "<<n<<" present (T/F) = "<<checkifPresent(head,n)<<endl;
    return 0;
}