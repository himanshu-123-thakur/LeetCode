//CODE
//Stack -> Data structure, can be implemented using array linked list queue
//LIFO
//push()/add(), pop(), top(), size()

//QUEUE -> FIFO data structure
//can store any type
//push(), top(), pop(), size()

//DEQUEUE -> very later at end we'll see


//STACK USING ARRAYS --> WE NEED TO KNOW THE SIZE 


//we dont implement ourself but how implwmeted in libraries



#include <iostream>
#include <stack>
#include <queue>

using namespace std;

//USING ARRAYS --> CONSTANT SO MEH not gooood

class stIMPL{
    int top  = -1;
    int st [10];

    void push(int x){
        if(top>=10){break;}
        top++;
        st[top]=x;            //O(1)
    }
    int top(){
        if(top==-1){break;}
        return st[top];     //O(1)
    }
    void pop(){
        if(top==-1){break;}
        top--;             //O(1)
    }
    void size(){
        return top+1;      //O(1)
    }
};


//QUEUE USING ARRAY --> constant SIZE
//start,end,first we'll keep both at -1

class QQ{
    size = 10;
    int q[10];
    int curr_size=0;
    int start = -1;
    int end = -1;

    bool isFull() {
        return curr_size == 10;
    }

    void push(int x){
        if (isFull()) {
            cout << "Queue Overflow\n";
            return;
        }
        if(curr_size==0){
            start =0;
            end = 0;
        }
        else{
            end = (end + 1)%10;
            q[end]=x;
            curr_size ++;
        }

    }

    void pop(){
        int first_elem = q[start];
        if(curr_size==0){break;}
        if(curr_size==1){//Destroy queue
            start=-1;
            end =-1;
        }
        else{
            start = (start+1)%10;
            curr_size--;
        }
    }

    int top() {     // front element
        if (isEmpty()) {
            cout << "Queue is Empty\n";
            return -1;
        }

        return arr[start];
    }

    int size() {
        return curr_size;
    }

}



//DYNAMIC IMPLEMENTATION 
//BOTH STACK AND QUEUE
//WE WILL USE LINKED LIST



//STACK --> LIFO
class sttack{

    Node* top = NULL;
    int size =0;
    void push(int x){
        Node* temp =new Node(x);
        temp->next = top;
        top = tmep;
        size++;
    }
    void pop(){
        Node* temp = top;
        top = top->next;
        delete temp;
        size--;
    }
    int top(){
        return top->data;
    }
    int ssize(){
        return size;
    }

};


//QUEUE
class queueueueue{
    Node* start = NULL;
    Node* end = NULL;
    int size =0;

    void push(int x){
        Node* temp = new Node (x);
        if(size==0){
            start = temp;
            end = temp;
            size=1;
        }
        else{
            end -> next = temp;
            end = temp;
            size++;
          }
    }

    void pop(){
        if(size == 0){
            break;
        }
        Node* temp = start;
        start = start->next;
        delete(temp);
        size--;
    }

    int top(){
        if(start==NULL){return NULL;}
        return start-> value;
    }
};



//IMPLEMENT STACK USING QUEUE
//FIFO  AS A LIFO
//JUST REVERSE THE QUEUE 

class queue_as_stack {
    queue<int> q;
    void push(int x){
        s = q.size();
        q.push(x);
        for(int i =0;i<s-1;i++){ //REVERSE AND IN ORDER
            q.push(q.top());
            q.pop();
        }
    }

    void pop(){
        q.pop();
    }

    int top(){
        return q.top();
    }
};


//IMPLEMET QUEUE USING STACK

class stack_as_queue{
    stack<int> s1,s2;
    void push(int x){
        while(s1.size()){
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(x);
        while(s2.size()){
            s1.push(s2.top());
            s2.pop()
        }
    }

    int top(){
        return s1.top();
    }

    void pop(){
        s1.pop();
    }
};
int main(){
    stack <int> st;
    queue <int> qe;


    return 0;
}