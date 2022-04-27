/*
    print all m element subsets of {1, 2, ..., n}
*/

#include <bits/stdc++.h>
using namespace std;

const int maxn = 20;
int subset[maxn];

void print(int m) {
    for (int i = 0; i < m; ++i) {
        cout << subset[i] << " ";
    }
    cout << endl;
}

void Try(int k, int n, int m) {
    if (k == 0) {
        for (int i = 0; i < n; ++i) {
            subset[k] = i;
            Try(k + 1, n, m);
        }
    } else
        for (int y = subset[k - 1] + 1; y < n; ++y) {
            subset[k] = y;
            if (k == m - 1) {
                print(m);
            } else {
                Try(k + 1, n, m);
            }
        }
}

void mSubset(int n, int m) {
    Try(0, n, m);
}

int main() {
    int n = 7, m = 3;
    mSubset(7, 3);
}