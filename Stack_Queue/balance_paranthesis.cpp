#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {

        stack<char> st; // stack to store opening brackets

        for(char c : s) {

            // If opening bracket → push into stack
            if(c == '(' || c == '{' || c == '[') {
                st.push(c);
            }

            else {

                // If stack empty but closing bracket appears
                if(st.empty())
                    return false;

                char top = st.top();

                // Check matching pair
                if( (c == ')' && top == '(') ||
                    (c == '}' && top == '{') ||
                    (c == ']' && top == '[') ) {

                    st.pop(); // valid pair
                }
                else {
                    return false; // mismatch
                }
            }
        }

        // If stack empty → valid
        return st.empty();
    }
};

int main() {

    Solution obj;

    string s = "{[()]}";

    if(obj.isValid(s))
        cout << "Valid Parentheses\n";
    else
        cout << "Invalid Parentheses\n";

    return 0;
}