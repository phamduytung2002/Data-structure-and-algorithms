#include <bits/stdc++.h>
using namespace std;

// compute a polynomial product between f(x) and (1+2x)

typedef struct Polynom {
    int coeff;
    int pow;
    struct Polynom *link;
} poly;

void print(poly *t) {
    for (poly *cur = t; cur != NULL; cur = cur->link) {
        cout << cur->coeff << " " << cur->pow << endl;
    }
}

poly *tichdathuc(poly *px) {
    poly *px2x = NULL, *px2xtail;
    for (poly *pp = px; pp != NULL; pp = pp->link) {
        poly *newnode = new poly;
        newnode->coeff = 2 * pp->coeff;
        newnode->pow = pp->pow + 1;
        newnode->link = NULL;
        if (px2x == NULL) {
            px2x = newnode;
            px2xtail = newnode;
        } else {
            px2xtail->link = newnode;
            px2xtail = px2xtail->link;
        }
    }
    poly *ans = NULL, *anstail;
    for (poly *pp = px, *px2xcur = px2x; pp != NULL || px2xcur != NULL;) {
        poly *newnode = new poly;
        newnode->link = NULL;
        if (pp != NULL && px2xcur != NULL && pp->pow == px2xcur->pow) {
            newnode->coeff = pp->coeff + px2xcur->coeff;
            newnode->pow = pp->pow;
            pp = pp->link;
            px2xcur = px2xcur->link;
        } else if (px2xcur == NULL || (pp!=NULL&&pp->pow < px2xcur->pow)) {
            newnode = pp;
            pp = pp->link;
        } else {
            newnode = px2xcur;
            px2xcur = px2xcur->link;
        }
        if (ans == NULL) {
            ans = newnode;
            anstail = newnode;
        } else {
            anstail->link = newnode;
            anstail = anstail->link;
        }
    }
    return ans;
}

int main() {
    poly *t0 = new poly;
    t0->coeff = 1;
    t0->pow = 0;
    poly *t1 = new poly;
    t1->coeff = 2;
    t1->pow = 1;
    t1->link = NULL;
    t0->link = t1;
    poly *head = t0;
    print(tichdathuc(head));
}