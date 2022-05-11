#include <bits/stdc++.h>
using namespace std;

struct node {
    int value;
    node *next;
};

node *makeNode(int v) {
    node *p = new node;
    p->value = v;
    p->next = NULL;
    return p;
}

void print(node *head) {
    while (head != NULL) {
        cout << head->value << " ";
        head = head->next;
    }
}


void insertToHead(node **head, int x) {
    node *newNode = makeNode(x);
    newNode->next = *head;
    *head = newNode;
}

node *insertToHead(node *head, int x) {
    node *newNode = makeNode(x);
    newNode->next = head;
    head = newNode;
    return head;
}

void insertAfter(node *cur, int x){
    node *newNode = makeNode(x);
    newNode->next = cur->next;
    cur->next = newNode;
}

int countNode(node *head, int v){
    int ans=0;
    while(head!=NULL){
        if(head->value == v) ans++;
        head = head->next;
    }
    return ans;
}

int main() {
    node *head = NULL;
    int n, val;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> val;
        insertToHead(head, val);
    }
    print(head);
    cout<<countNode(head, 5);
}