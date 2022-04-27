/*
    print all solutions of n-queens puzzle
*/

#include <bits/stdc++.h>
using namespace std;

const int maxn = 10;
int col[maxn];

bool check(int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (abs(col[i] - col[j]) == j - i) return false;
            if (i + col[i] == j + col[j]) return false;
        }
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) col[i] = i;
    do {
        if (check(n)) {
            cout << "CASE:\n";
            for (int i = 0; i < n; ++i) {
                cout << i << " " << col[i] << endl;
            }
        }
    } while (next_permutation(col, col + n));
}