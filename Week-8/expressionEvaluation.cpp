#include <bits/stdc++.h>
using namespace std;

stack<double> num;
stack<char> operators;

string trim(string s) {
    // remove the spaces at the start and end of string
    s.erase(s.find_last_not_of(" \n\r\t") + 1);
    s.erase(0, s.find_first_not_of(' '));
    return s;
}

string takeBeforeSpaceAndRemove(string &input) {
    // input = "    A       B.......     "
    // -> return A, input := B.......
    string A;
    input = trim(input);
    size_t found = input.find(" ");
    if (found == string::npos) {
        A = input;
        input = "";
    } else {
        A = input.substr(0, found);
        input = input.substr(found + 1, input.size());
    }
    A = trim(A);
    input = trim(input);
    return A;
}

bool isNum(string c) {
    // check if a string c is a number
    for (int i = 0; i < c.size(); ++i)
        if (c[i] != '.' && (c[i] < '0' || c[i] > '9')) return false;
    return true;
}

bool isOperator(string c) {
    if (c == "+" || c == "-" || c == "*" || c == "/" || c == "^")
        return true;
    else
        return false;
}

double stringToDouble(string c) {
    char *pEnd;
    return strtod(c.c_str(), &pEnd);
}

int priority(char c) {
    // return the priority of an (operator or bracket) c
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return 0;
}

void process() {
    // process top 2 elements in num stack with top element in operators stack
    double a = num.top();
    num.pop();
    double b = num.top();
    num.pop();
    char op = operators.top();
    operators.pop();
    if (op == '+')
        num.push(b + a);
    else if (op == '-')
        num.push(b - a);
    else if (op == '*')
        num.push(b * a);
    else if (op == '/')
        num.push(b / a);
    else if (op == '^')
        num.push(pow(b, a));
}

int main() {
    string input;
    getline(cin, input);
    input = trim(input);
    while (input != "") {
        string c = takeBeforeSpaceAndRemove(input);
        if (isNum(c)) {
            num.push(stringToDouble(c));
        } else if (isOperator(c)) {
            while (operators.size() > 0 && priority(operators.top()) >= priority(c[0]))
                process();
            operators.push(c[0]);
        } else if (c == "(") {
            operators.push(c[0]);
        } else if (c == ")") {
            while (operators.top() != '(') {
                if (operators.size() == 0) {
                    cout << "bieu thuc khong hop le";
                    return 0;
                }
                process();
            }
            operators.pop();
        } else {
            cout << "bieu thuc khong hop le";
            return 0;
        }
    }
    while (operators.size() > 0) {
        process();
    }
    cout << "ket qua: " << num.top();
}