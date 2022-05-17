#include <bits/stdc++.h>
using namespace std;

struct dblist {
    int data;
    dblist *prev;
    dblist *next;
};
dblist *head, *tail;

void printListFromHead(dblist **head) {
    cout << "List from head: " << endl;
    dblist *p = *head;
    while (p != NULL) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

void printListFromTail(dblist **tail) {
    cout << "List from tail: " << endl;
    dblist *p = *tail;
    while (p != NULL) {
        cout << p->data << " ";
        p = p->prev;
    }
    cout << endl;
}

void insertAfter(int x, dblist *p) {
    dblist *newNode = new dblist;
    newNode->data = x;
    newNode->next = p->next;
    newNode->prev = p;
    if (p != tail)
        p->next->prev = newNode;
    else
        tail = newNode;
    p->next = newNode;
}

void deleteNode(dblist *p) {
    if (p != head)
        p->prev->next = p->next;
    else
        head = head->next;

    if (p != tail)
        p->next->prev = p->prev;
    else
        tail = tail->prev;

    delete p;
}

int main() {
    dblist *p = new dblist;
    p->prev = NULL;
    p->data = 12;
    p->next = NULL;
    head = p;
    tail = p;
    insertAfter(34, p);
    insertAfter(56, p->next);
    deleteNode(p->next);
    printListFromHead(&head);
    printListFromTail(&tail);
}