/*
    find all positive solution of x_1+x_2+...+x_n = N
*/

#include <bits/stdc++.h>
using namespace std;

const int maxn = 20;
int N, n, x[maxn];
int cnt = 0;

void print(int t) {
    for (int i = 0; i < t; ++i) cout << x[i] << " ";
    cout << endl;
    ++cnt;
}

void Try(int k) {
    int M = 0;
    for (int i = 0; i < k; ++i) M += x[i];
    if (k == n - 1) {
        x[k] = N - M;
        print(n);
    } else
        for (int i = 1; i <= N - M - n + k + 1; ++i) {
            x[k] = i;
            Try(k + 1);
        }
}

int main() {
    cin >> n >> N;
    Try(0);
    cout<<"Number of solutions: "<<cnt<<endl;
}