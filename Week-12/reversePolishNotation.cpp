#include <bits/stdc++.h>
using namespace std;

bool isNum(char s) {
    if (s <= '9' && s >= '0') return true;
    return false;
}

bool isOperator(char s) {
    return (s == '+' || s == '-' || s == '*' || s == '/' || s == '^');
}

int priorityCal(char x) {
    if (x == '+' || x == '-') return 1;
    if (x == '*' || x == '/') return 2;
    if (x == '^') return 3;
    return 0;
}

int firstPos(string s, string substr) {
    int t = int(s.find(substr));
    return (t == -1 ? s.size() : t);
}

double stringToDouble(string c) {
    char *pEnd;
    return strtod(c.c_str(), &pEnd);
}

string infixToPostfix(string s) {
    string EH = "";
    stack<char> opstack;
    while (s != "") {
        if (isNum(s[0])) {
            int len = min(firstPos(s, "+"), firstPos(s, "-"));
            len = min(len, firstPos(s, "*"));
            len = min(len, firstPos(s, "/"));
            len = min(len, firstPos(s, "^"));
            len = min(len, firstPos(s, ")"));
            string curnum = s.substr(0, len);
            s = s.substr(curnum.size(), s.size() - curnum.size());
            EH += curnum;
            EH += " ";
        } else if (s[0] == '(') {
            opstack.push(s[0]);
            s.erase(0, 1);
        } else if (isOperator(s[0])) {
            while (true) {
                if (opstack.empty() || opstack.top() == '(') {
                    opstack.push(s[0]);
                    s.erase(0, 1);
                    break;
                } else if (priorityCal(opstack.top()) < priorityCal(s[0])) {
                    opstack.push(s[0]);
                    s.erase(0, 1);
                    break;
                } else {
                    EH += opstack.top();
                    EH += " ";
                    opstack.pop();
                }
            }
        } else {
            s.erase(0, 1);
            while (!opstack.empty() && isOperator(opstack.top())) {
                EH += opstack.top();
                EH += " ";
                opstack.pop();
            }
            if (!opstack.empty() && opstack.top() == '(') opstack.pop();
        }
    }
    while (!opstack.empty()) {
        EH += opstack.top();
        EH += " ";
        opstack.pop();
    }
    return EH;
}
double postfixCal(string postfix) {
    stack<double> num;
    while (postfix.size() > 0) {
        while (postfix[0] == ' ') postfix.erase(0, 1);
        string current = postfix.substr(0, postfix.find(" "));
        if (isOperator(current[0])) {
            double sau = num.top();
            num.pop();
            double truoc = num.top();
            num.pop();
            double newnum;
            if (current == "+")
                newnum = truoc + sau;
            else if (current == "-")
                newnum = truoc - sau;
            else if (current == "*")
                newnum = truoc * sau;
            else if (current == "/")
                newnum = truoc / sau;
            else if (current == "^")
                newnum = pow(truoc, sau);
            num.push(newnum);
            postfix.erase(0, 2);
        } else {
            num.push(stringToDouble(postfix.substr(0, postfix.find(" "))));
            postfix.erase(0, postfix.find(" "));
        }
    }
    return num.top();
}

int main() {
    string s;
    cin >> s;
    cout << "Postfix notation: " << infixToPostfix(s) << endl;
    cout << "Result: " << postfixCal(infixToPostfix(s));
}