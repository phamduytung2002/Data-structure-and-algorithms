#include <bits/stdc++.h>
using namespace std;

const int maxn = 10;
int a[maxn];

// void cheating() {
//     do {
//         for (int i = 0; i < 5; ++i) {
//             cout << a[i];
//         }
//         cout << endl;
//     } while (next_permutation(a, a + 5));
// }

void print(int n) {
    for (int i = 0; i < n; ++i) {
        cout << a[i];
    }
    cout << endl;
}

bool chk(int i, int k) {
    for (int j = 0; j < k; ++j) {
        if (a[j] == i) return false;
    }
    return true;
}

void Try(int k, int n) {
    for (int i = 0; i < n; ++i) {
        if (!chk(i, k)) continue;
        a[k] = i;
        if (k == n - 1)
            print(n);
        else
            Try(k + 1, n);
    }
}

void permutation(int n) {
    Try(0, n);
}

int main() {
    int n = 5;
    permutation(n);
}