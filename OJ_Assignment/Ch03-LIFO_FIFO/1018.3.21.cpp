#include <iostream>
#include <cctype>

using namespace std;

constexpr int strlen = 100;

int val[strlen];
int top = 0;

bool IsStackEmpty() {
    return top == 0;
}

int GetTop() {
    if (top == 0) {
        return 0;
    }
    return val[top - 1];
}

bool Push(int e) {
    if (top == strlen) {
        return false;
    }
    val[top++] = e;
    return true;
}

int Pop() {
    if (top == 0) {
        return 0;
    }
    return val[--top];
}

bool OpLevelHigher(char op1, char op2) {
    if (op1 == '(') {
        return false;
    }
    if ((op2 == '*' || op2 == '/') && (op1 == '+' || op1 == '-')) {
        return false;
    }
    return true;
}

int main() {
    char input[strlen], rpn[strlen];
    
    cin >> input;
    
    int i, j = 0;
    for (i = 0; input[i] != 0; ++i) {
        if (isalpha(input[i])) {
            rpn[j++] = input[i];
        } else if (input[i] == '(') {
            Push(input[i]);
        } else if (input[i] == ')') {
            while (!IsStackEmpty() && GetTop() != '(') {
                rpn[j++] = Pop();
            }
            Pop();
        } else {
            while (!IsStackEmpty() && OpLevelHigher(GetTop(), input[i])) {
                rpn[j++] = Pop();
            }
            Push(input[i]);
        }
    }
    while (!IsStackEmpty()) {
        rpn[j++] = Pop();
    }
    rpn[j] = '\0';

    cout << rpn << endl;
    
    return 0;
}
