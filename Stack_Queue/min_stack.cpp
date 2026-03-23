#include <bits/stdc++.h>
using namespace std;
int main(){
    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
// Print stack (without modifying original)
    stack<int> temp = st;
    while(!temp.empty()){
        cout << temp.top() << " ";
        temp.pop();
    }
    cout << endl;

    cout << st.top() << endl;

    st.pop();

    temp = st;
    while(!temp.empty()){
        cout << temp.top() << " ";
        temp.pop();
    }

    return 0;
}