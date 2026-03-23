/*
INFIX → POSTFIX (SHORT RULE + FULL CASE EXAMPLE)

Expression: (A+B^C-D)*E

Rules:
- Operand → add to output
- '(' → push
- ')' → pop till '('
- Operator → pop higher/equal priority, then push
- End → pop all

Priority:
^ > * / > + -

------------------------------------------------

Steps:

(A+B^C-D)*E

( → push
A → output: A
+ → push
B → output: AB
^ → push (higher than +)
C → output: ABC
- → pop ^ and + → output: ABC^+
      push -
D → output: ABC^+D
) → pop - → output: ABC^+D-
* → push
E → output: ABC^+D-E
END → pop *

Final Answer:
ABC^+D-E*

*/






/*
================ INFIX → PREFIX RULE =================

Trick (VERY IMPORTANT):

1) Reverse the infix expression
2) Swap brackets:
   '(' ↔ ')'
3) Convert to POSTFIX
4) Reverse the result → PREFIX

-----------------------------------------------------
*/



/*
================ POSTFIX → INFIX RULE =================

Use a STACK of strings

-----------------------------------------------------

For each character:

1) If operand (A–Z, a–z, 0–9)
   → push as string

2) If operator (+, -, *, /, ^)
   → pop TWO elements:
        op2 = top
        op1 = next top
   → make string:
        "(" + op1 + operator + op2 + ")"
   → push result back

-----------------------------------------------------

End:
Top of stack = final INFIX expression

-----------------------------------------------------
*/


/*
/*
================ PREFIX → INFIX RULE =================

Use a STACK of strings

-----------------------------------------------------

Scan expression RIGHT → LEFT

-----------------------------------------------------

For each character:

1) If operand (A–Z, a–z, 0–9)
   → push as string

2) If operator (+, -, *, /, ^)
   → pop TWO elements:
        op1 = top
        op2 = next top
   → make string:
        "(" + op1 + operator + op2 + ")"
   → push result back

-----------------------------------------------------

End:
Top of stack = final INFIX expression
*/

/*
/*
================ POSTFIX → PREFIX RULE =================

Use a STACK of strings

-----------------------------------------------------

Scan expression LEFT → RIGHT

-----------------------------------------------------

For each character:

1) If operand (A–Z, a–z, 0–9)
   → push as string

2) If operator (+, -, *, /, ^)
   → pop TWO elements:
        op2 = top
        op1 = next top
   → make string:
        operator + op1 + op2
   → push result back

-----------------------------------------------------
*/


/*
/*
================ PREFIX → POSTFIX RULE =================

Use a STACK of strings

-----------------------------------------------------

Scan expression RIGHT → LEFT

-----------------------------------------------------

For each character:

1) If operand (A–Z, a–z, 0–9)
   → push as string

2) If operator (+, -, *, /, ^)
   → pop TWO elements:
        op1 = top
        op2 = next top
   → make string:
        op1 + op2 + operator
   → push result back

-----------------------------------------------------
*/
















/*
-----------------------------------------------------------------------

ONE-LINE TRICKS:

Infix → Postfix  → use stack + precedence  
Infix → Prefix   → reverse → postfix → reverse  
Postfix → Infix  → pop2 → (op1 op op2)  
Prefix → Infix   → right→left → pop2  
Postfix → Prefix → pop2 → op op1 op2  
Prefix → Postfix → pop2 → op1 op2 op  

=======================================================================
*/












#include <iostream>
#include <stack>
using namespace std;

// precedence function
int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

string infixToPostfix(string exp) {
    stack<char> st;
    string result = "";

    for (char c : exp) {

        // 🔹 OPERAND CHECK (manual)
        if ((c >= 'A' && c <= 'Z') ||
            (c >= 'a' && c <= 'z') ||
            (c >= '0' && c <= '9')) {

            result += c;
        }

        // 🔹 '('
        else if (c == '(') {
            st.push(c);
        }

        // 🔹 ')'
        else if (c == ')') {
            while (!st.empty() && st.top() != '(') {
                result += st.top();
                st.pop();
            }
            st.pop(); // remove '('
        }

        // 🔹 OPERATOR
        else {
            while (!st.empty() && precedence(st.top()) >= precedence(c)) {
                result += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    // 🔹 remaining stack
    while (!st.empty()) {
        result += st.top();
        st.pop();
    }

    return result;
}

int main() {
    string exp = "(A+B)*C";

    cout << "Postfix: " << infixToPostfix(exp) << endl;

    return 0;
}