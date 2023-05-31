#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* pLeft;
    struct Node* pRight;
};

typedef struct Node sNode;

typedef struct {
    sNode* pRoot;
} bst;

bst* create() {
    bst* t = (bst*)malloc(sizeof(bst));
    t->pRoot = NULL;
    return t;
}

void insert(bst* t, int x) {
    sNode* newNode = (sNode*)malloc(sizeof(sNode));
    newNode->data = x;
    newNode->pLeft = NULL;
    newNode->pRight = NULL;

    if (t->pRoot == NULL) {
        t->pRoot = newNode;
        return;
    }

    sNode* current = t->pRoot;
    while (1) {
        if (x < current->data) {
            if (current->pLeft == NULL) {
                current->pLeft = newNode;
                return;
            }
            current = current->pLeft;
        }
        else if (x > current->data) {
            if (current->pRight == NULL) {
                current->pRight = newNode;
                return;
            }
            current = current->pRight;
        }
        else {
            return;
        }
    }
}

sNode* search(bst* t, int x) {
    sNode* current = t->pRoot;
    while (current != NULL && current->data != x) {
        if (x < current->data) {
            current = current->pLeft;
        }
        else {
            current = current->pRight;
        }
    }
    return current;
}

void inorder(sNode* pPointer) {
    if (pPointer != NULL) {
        inorder(pPointer->pLeft);
        printf("%d ", pPointer->data);
        inorder(pPointer->pRight);
    }
}

void preorder(sNode* pPointer) {
    if (pPointer != NULL) {
        printf("%d ", pPointer->data);
        preorder(pPointer->pLeft);
        preorder(pPointer->pRight);
    }
}

void postorder(sNode* pPointer) {
    if (pPointer != NULL) {
        postorder(pPointer->pLeft);
        postorder(pPointer->pRight);
        printf("%d ", pPointer->data);
    }
}

sNode* maximum(sNode* pPointer) {
    while (pPointer->pRight != NULL) {
        pPointer = pPointer->pRight;
    }
    return pPointer;
}

sNode* minimum(sNode* pPointer) {
    while (pPointer->pLeft != NULL) {
        pPointer = pPointer->pLeft;
    }
    return pPointer;
}

sNode* parent(bst* t, int x) {
    sNode* current = t->pRoot;
    sNode* parent = NULL;

    while (current != NULL && current->data != x) {
        parent = current;
        if (x < current->data) {
            current = current->pLeft;
        }
        else {
            current = current->pRight;
        }
    }

    if (current != NULL) {
        return parent;
    }
    else {
        return NULL;
    }
}

sNode* successor(bst *t, int x) {
    sNode* current = search(t, x);

    if (current == NULL) {
        return NULL;
    }

    if (current->pRight != NULL) {
        return minimum(current->pRight);
    }
    else {
        sNode* p = parent(t, x);
        while (p != NULL && current == p->pRight) {
            current = p;
            p = parent(t, p->data);
        }
        return p;
    }
}

sNode* predecessor(bst *t, int x) {
    sNode* current = search(t, x);

    if (current == NULL) {
        return NULL;
    }

    if (current->pLeft != NULL) {
        return maximum(current->pLeft);
    }
    else {
        sNode* p = parent(t, x);
        while (p != NULL && current == p->pLeft) {
            current = p;
            p = parent(t, p->data);
        }
        return p;
    }
}
