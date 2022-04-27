/*
    print all binary strings of length n
*/

#include <bits/stdc++.h>
using namespace std;

const int maxn = 20;
bool a[maxn];

void print(int n) {
    for (int i = 0; i < n; ++i) {
        cout << a[i];
    }
    cout << endl;
}

void Try(int k, int n) {
    for (int y = 0; y <= 1; ++y) {
        a[k] = y;
        if (k == n - 1) {
            print(n);
        } else
            Try(k + 1, n);
    }
}

int main() {
    int n;
    cin >> n;
    Try(0, n);
}