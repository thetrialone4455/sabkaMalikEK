#include <iostream>
#include <stack>
using namespace std;

int applyOp(int a, int b, char op) {
    if (op == '+') return a + b;
    if (op == '-') return a - b;
    if (op == '*') return a * b;
    if (op == '/') return a / b;
    return 0;
}

int evaluatePostfix(string postfix) {
    stack<int> st;

    for (char ch : postfix) {
        if (ch >= '0' && ch <= '9') {
            st.push(ch - '0');
        }
        else if (isOperator(ch)) {
            int b = st.top(); st.pop();
            int a = st.top(); st.pop();
            st.push(applyOp(a, b, ch));
        }
    }
    return st.top();
}

int main() {
    cout << evaluatePostfix("231*+9-");
    return 0;
}
