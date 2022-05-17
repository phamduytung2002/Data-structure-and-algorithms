#include <bits/stdc++.h>
using namespace std;

int main() {
    list<int> a;
    a.push_back(10);
    a.push_back(20);
    a.push_back(30);
    a.push_front(100);
    a = list<int>();
    a.push_back(30);
    a.push_front(100);
    for (list<int>::iterator p = a.begin(); p != a.end(); ++p) {
        cout << *p << endl;
    }
}