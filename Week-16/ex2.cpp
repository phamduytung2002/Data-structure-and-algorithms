#include <bits/stdc++.h>
using namespace std;

struct thongTin {
    string ho;
    string dem;
    string ten;
    int ngaySinh;
    int thangSinh;
    int namSinh;
};

bool cmp(thongTin a, thongTin b) {
    if (a.ten < b.ten) return 1;
    if (a.dem < b.dem) return 1;
    if (a.ho < b.ho) return 1;
    if (a.namSinh < b.namSinh) return 1;
    if (a.thangSinh < b.thangSinh) return 1;
    if (a.ngaySinh < b.ngaySinh) return 1;
    return 0;
}

thongTin tt[100];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> tt[i].ho;
        cin >> tt[i].dem;
        cin >> tt[i].ten;
        cin >> tt[i].ngaySinh;
        cin >> tt[i].thangSinh;
        cin >> tt[i].namSinh;
    }
    sort(tt, tt + n, cmp);
    for (int i = 0; i < n; ++i) {
        cout << tt[i].ho << " " << tt[i].dem << " " << tt[i].ten << " " << tt[i].ngaySinh << " " << tt[i].thangSinh << " " << tt[i].namSinh << endl;
    }
}