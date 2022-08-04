#include <bits/stdc++.h>
using namespace std;

struct submission {
    string ngay;
    string gio;
    string ten;
    string assignmentID;
};

struct sub {
    string ngay;
    int cnt;
};

bool cmp(submission a, submission b) {
    return a.ngay < b.ngay;
}

submission s[100];

int main() {
    freopen("Week-16\\test.txt", "r", stdin);
    int i = 0;
    while (true) {
        cin >> s[i].ngay;
        if (s[i].ngay[0] == '*') break;
        cin >> s[i].gio;
        cin >> s[i].ten;
        cin >> s[i].assignmentID;
        ++i;
    }
    sort(s, s + i, cmp);
    int cnt = 1;
    for (int j = 1; j <= i; ++j) {
        if (j == i) {
            cout << s[j - 1].ngay << " " << cnt << endl;
            break;
        }
        if (s[j].ngay == s[j - 1].ngay)
            cnt++;
        else {
            cout << s[j - 1].ngay << " " << cnt << endl;
            cnt = 1;
        }
    }
}