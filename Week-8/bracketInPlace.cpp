#include <bits/stdc++.h>
using namespace std;

bool checkBracket(string str) {
    stack<char> s;
    for (int i = 0; i < str.size(); ++i) {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{')
            s.push(str[i]);
        else if (str[i] == ')' || str[i] == ']' || str[i] == '}') {
            if (s.empty()) return 0;
            char t = s.top();
            s.pop();
            if (str[i] == ')' && t == '(')
                continue;
            else if (str[i] == ']' && t == '[')
                continue;
            else if (str[i] == '}' && t == '{')
                continue;
            else
                return false;
        }
    }
    if (s.empty())
        return true;
    else
        return false;
}

int main() {
    string str;
    cin >> str;
    if (checkBracket(str))
        cout << "Correct brackets";
    else
        cout << "Wrong brackets";
}