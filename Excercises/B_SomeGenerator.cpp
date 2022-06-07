#include <bits/stdc++.h>
using namespace std;

void print(int A[], int n) {
    for (int i = 0; i < n; ++i) cout << A[i];
    cout << " ";
}

void Generate(int lev, int A[], int n) {
    if (lev == n) print(A, n);
    for (A[lev] = lev; A[lev] < n; A[lev]++) Generate(lev + 1, A, n);
}

int main() {
    int A[3];
    Generate(0,A,3);
}