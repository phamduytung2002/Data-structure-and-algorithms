#include <bits/stdc++.h>
using namespace std;

struct StackNode {
    float item;
    StackNode *next;

    StackNode() {
        this->item = 0;
        this->next = NULL;
    }
};
struct Stack {
    StackNode *top;
    int size;
    int maxSize;

    Stack() {
        this->top = NULL;
        this->size = 0;
        this->maxSize = 5;
    }
};

Stack *StackConstruct() {
    Stack *s = new Stack();
    return s;
}

bool StackEmpty(Stack *s) {
    return (s->size == 0);
}

bool StackFull(Stack *s) {
    return (s->size == s->maxSize);
}

int StackPush(Stack *s, float item) {
    if (!StackFull(s)) {
        StackNode *newNode = new StackNode;
        newNode->next = s->top;
        newNode->item = item;
        s->top = newNode;
        s->size++;
        return 0;
    } else
        return 1;
}

float StackPop(Stack *s) {
    if (!StackEmpty(s)) {
        float t = s->top->item;
        StackNode *top = s->top;
        s->top = s->top->next;
        delete top;
        s->size--;
        return t;
    }
    return 0;
}

void Disp(Stack *s) {
    StackNode *p = s->top;
    while (p != NULL) {
        cout << p->item << " ";
        p = p->next;
    }
    cout << endl;
}

int main() {
    Stack *s = StackConstruct();
    StackPush(s, 5678);
    StackPush(s, 1234);
    StackPop(s);
    Disp(s);
}