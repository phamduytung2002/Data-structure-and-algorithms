#include <bits/stdc++.h>
using namespace std;

typedef struct _List {
    int info;
    struct _List *linkhang;
    struct _List *linkcot;
} listt;

void print(listt *t) {
    cout << "t";
    for (listt *cur = t; cur != NULL;) {
        cout << cur->info << " ";
        if (cur->linkhang == NULL)
            cur = cur->linkcot;
        else
            cur = cur->linkhang;
    }
}

listt *CreateSudokulist(int **p) {
    listt *SDK = NULL;
    listt *cottail, *hangtail, *hangtailprev = NULL;
    for (int hang = 0; hang < 9; hang++) {
        for (int cot = 0; cot < 9; cot++) {
            listt *newnode = new listt;
            newnode->info = p[hang][cot];
            newnode->linkhang = NULL;
            newnode->linkcot = NULL;
            if (SDK == NULL) {
                SDK = newnode;
                cottail = newnode;
                hangtail = newnode;
            } else if (cot == 0) {
                hangtailprev = hangtail;
                hangtail->linkhang = newnode;
                cottail = newnode;
                hangtail = hangtail->linkhang;
            } else {
                if (hangtailprev != NULL) {
                    hangtailprev = hangtailprev->linkcot;
                    hangtailprev->linkhang = newnode;
                }
                cottail->linkcot = newnode;
                cottail = cottail->linkcot;
            }
        }
    }
    return SDK;
}

bool check3x3(listt *t) {
    bool chk[9];
    chk[t->info - 1] = 1;
    chk[t->linkcot->info - 1] = 1;
    chk[t->linkcot->linkcot->info - 1] = 1;
    chk[t->linkhang->info - 1] = 1;
    chk[t->linkhang->linkcot->info - 1] = 1;
    chk[t->linkhang->linkcot->linkcot->info - 1] = 1;
    chk[t->linkhang->linkhang->info - 1] = 1;
    chk[t->linkhang->linkhang->linkcot->info - 1] = 1;
    chk[t->linkhang->linkhang->linkcot->linkcot->info - 1] = 1;
    for (int i = 0; i < 9; ++i)
        if (!chk[i])
            return 0;
    return 1;
}

int CheckSudokuCondition(listt *head) {
    for (listt *cur = head; cur != NULL; cur = cur->linkhang) {
        bool chk[9];
        for (listt *curcot = cur; curcot != NULL; curcot = curcot->linkcot) {
            if (curcot->info > 9 || curcot->info < 1) return 0;
            chk[curcot->info - 1] = 1;
        }
        for (int i = 0; i < 9; ++i) {
            if (!chk[i]) return 0;
        }
    }
    for (listt *cur = head; cur != NULL; cur = cur->linkcot) {
        bool chk[9];
        for (listt *curhang = cur; curhang != NULL; curhang = curhang->linkhang) {
            if (curhang->info > 9 || curhang->info < 1) return 0;
            chk[curhang->info - 1] = 1;
        }
        for (int i = 0; i < 9; ++i)
            if (!chk[i]) return 0;
    }
    if (check3x3(head) &&
        check3x3(head->linkhang->linkhang->linkhang) &&
        check3x3(head->linkhang->linkhang->linkhang->linkhang->linkhang->linkhang) &&
        check3x3(head->linkcot->linkcot->linkcot) &&
        check3x3(head->linkcot->linkcot->linkcot->linkhang->linkhang->linkhang) &&
        check3x3(head->linkcot->linkcot->linkcot->linkhang->linkhang->linkhang->linkhang->linkhang->linkhang) &&
        check3x3(head->linkcot->linkcot->linkcot->linkcot->linkcot->linkcot) &&
        check3x3(head->linkcot->linkcot->linkcot->linkcot->linkcot->linkcot->linkhang->linkhang->linkhang) &&
        check3x3(head->linkcot->linkcot->linkcot->linkcot->linkcot->linkcot->linkhang->linkhang->linkhang->linkhang->linkhang->linkhang))
        return 1;
    return 0;
}

int main() {
    int **p = new int *[9];
    for (int i = 0; i < 9; ++i) p[i] = new int[9];
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) cin >> p[i][j];
    }
    cout << CheckSudokuCondition(CreateSudokulist(p));
}
