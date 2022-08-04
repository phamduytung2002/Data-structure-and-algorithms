#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000005;
int a[maxn], n, Q;

int main() {
    freopen("Week-16\\test1Mil.txt", "r", stdin);
    freopen(".out", "w", stdout);
    cin >> n;
    cin >> Q;
    for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a, a + n);
    int i = 0, j = n - 1, ans = 0;
    while (i < j) {
        if (a[i] + a[j] == Q) {
            ans++;
            i++;
        } else if (a[i] + a[j] < Q) {
            i++;
        } else
            j--;
    }
    cout << ans << endl;
}