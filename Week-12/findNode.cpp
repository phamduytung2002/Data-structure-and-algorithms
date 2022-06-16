#include <bits/stdc++.h>
using namespace std;

typedef struct Node {
    char name[256];
    struct Node* leftMostChild;
    struct Node* rightSibling;
} Node;
Node* root;

Node* find(Node* root, char* name) {
    if (root == NULL)
        return NULL;
    else {
        if (strcmp(root->name, name) == 0)
            return root;
        else {
            if (root->leftMostChild == NULL && root->rightSibling == NULL)
                return NULL;
            else {
                Node* lmc = find(root->leftMostChild, name);
                if (lmc == NULL)
                    return find(root->rightSibling, name);
                else
                    return lmc;
            }
        }
    }
}

void addChild(char* nameP, char* nameC) {
    Node* nodeToAdd = find(root, nameP);
    Node* child = nodeToAdd->leftMostChild;
    if (child == NULL) child = 0;
    while (child->rightSibling != NULL) child = child->rightSibling;
}

int main() {
    Node *root, *con1, *con2, *con3, *chau11, *chau12, *chau21;
}