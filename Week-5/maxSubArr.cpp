/*
    consecutive subarray with maximum sum of elements
*/

#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000;
int a[maxn] = {-1, -4, -7, -4, -1, -29, -5}, mem[maxn];
bool comp[maxn];

int max_sum(int i) {
    if (comp[i] == false) {
        if (i == 0)
            mem[i] = a[i];
        else
            mem[i] = max(a[i], a[i] + max_sum(i - 1));
    }
    comp[i] = true;
    return mem[i];
}

void trace(int i) {
    if (i != 1 && mem[i] == a[i] + mem[i - 1]) trace(i - 1);
    cout << a[i] << " ";
}

int main() {
    int n = 7;
    max_sum(n);
    int ans = INT_MIN;
    int lastPos;
    for (int i = 0; i < n; ++i) {
        if (ans < mem[i]) {
            lastPos = i;
            ans = mem[i];
        }
    }
    trace(lastPos);
    system("pause");
}