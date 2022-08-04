#include <bits/stdc++.h>
using namespace std;

typedef struct Node {
    char id[256];
    struct Node *leftMostChild;
    struct Node *rightSibling;
} Node;

Node *newNode(char id[], Node *leftMostChild, Node *rightSibling) {
    Node *nn = new Node;
    copy(id, id + 256, nn->id);
    nn->leftMostChild = leftMostChild;
    nn->rightSibling = rightSibling;
    return nn;
}

int countNodes(Node *root) {
    if (root == NULL) return 0;
    return countNodes(root->leftMostChild) + countNodes(root->rightSibling);
}

Node *find(Node *root, char *idF) {
    if (root == NULL) return NULL;
    if (root->id == idF) return root;
    Node *findSibling = find(root->rightSibling, idF);
    if (findSibling == NULL)
        return find(root->leftMostChild, idF);
    else
        return findSibling;
}

void addChild(Node *root, char *idP, char *idC) {
    Node *findNode = find(root, idP);
    if (findNode == NULL)
        return;
    else {
        findNode = findNode->leftMostChild;
        while (findNode->rightSibling != NULL) findNode = findNode->rightSibling;
        Node *nn = new Node;

        findNode->rightSibling = newNode(idC, NULL, NULL);
    }
}

int main() {
}