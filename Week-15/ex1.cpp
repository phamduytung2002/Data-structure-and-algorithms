#include <bits/stdc++.h>
using namespace std;

const int maxn = 100001;
int h[maxn];
int n, m;  // n cay, can m met go

int soMetGoThuDuoc(int t) {
    int tongSoMetGo = 0;
    for (int i = 0; i < n; ++i) tongSoMetGo += max(0, h[i] - t);
    return tongSoMetGo;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) cin >> h[i];
    int tongGo = 0, hmax = 0;
    for (int i = 0; i < n; ++i) {
        tongGo += h[i];
        hmax = max(hmax, h[i]);
    }
    if (m > tongGo) {
        cout << "khong cat duoc!\n";
        return 0;
    }

    // binary search
    int ans = 0;
    for (int b = hmax / 2; b >= 1; b /= 2) {
        while (ans + b <= hmax && soMetGoThuDuoc(ans + b) >= m) ans += b;
    }
    cout << ans << endl;
}