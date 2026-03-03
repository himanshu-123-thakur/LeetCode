#include <iostream>
#include <queue>
#include <stack>

using namespace std;

int main() {

    queue<int> q;

    q.push(10);
    q.push(20);
    q.push(30);

    cout << "Front: " << q.front() << endl;   // 10
    cout << "Back: " << q.back() << endl;     // 30
    cout << "Size: " << q.size() << endl;     // 3

    q.pop();   // removes 10

    cout << "Front after pop: " << q.front() << endl; // 20
    cout << "Size after pop: " << q.size() << endl;   // 2




    stack<int> st;

    st.push(10);
    st.push(20);
    st.push(30);

    cout << "Top: " << st.top() << endl;   // 30
    cout << "Size: " << st.size() << endl; // 3

    st.pop();   // removes 30

    cout << "Top after pop: " << st.top() << endl; // 20
    cout << "Size after pop: " << st.size() << endl; // 2




    /*
QUEUE    | Function  | Meaning            |
| --------- | ------------------ |
| `push(x)` | insert at back     |
| `pop()`   | remove front       |
| `front()` | first element      |
| `back()`  | last element       |
| `empty()` | check empty        |
| `size()`  | number of elements |


STACK | Function  | Meaning            |
| --------- | ------------------ |
| `push(x)` | insert             |
| `pop()`   | remove top         |
| `top()`   | top element        |
| `empty()` | check empty        |
| `size()`  | number of elements |


    */
    return 0;
}