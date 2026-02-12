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

bool hasCycle (Node* head){
    unordered_map <Node* , bool> mp;
    Node *temp = head;
    while(temp){
        if(mp[temp]==false){
        mp[temp]=true;
        temp = temp->next;
        }
        else{
            return true;
        }
    }
    return false;
}

// int main(){

//     vector<int> arr{10,20,30,40,50};

//     Node *head = convertToLL(arr);

//     // Create loop:
//     // 50 → 30
//     Node* temp = head;
//     Node* thirdNode = nullptr;

//     int count = 1;
//     while(temp->next != nullptr){
//         if(count == 3)   // Save address of node 30
//             thirdNode = temp;

//         temp = temp->next;
//         count++;
//     }

//     // temp is now last node (50)
//     temp->next = thirdNode;   // 🔥 LOOP CREATED

//     // Now list looks like:
//     // 10 → 20 → 30 → 40 → 50
//     //               ↑      ↓
//     //               ← ← ← ←

//     if(hasCycle(head))
//         cout << "Cycle Detected\n";
//     else
//         cout << "No Cycle\n";

//     return 0;
// }


int main(){

    vector<int> arr{10,20,30,40,50};

    Node *head = convertToLL(arr);


    cout << endl;

    if(hasCycle(head))
        cout << "Cycle Detected\n";
    else
        cout << "No Cycle\n";

    return 0;
}
