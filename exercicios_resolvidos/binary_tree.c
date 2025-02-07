#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node *left;
    struct node *right;
} Tree;

void pushTree(Tree **binTree, int val) {
    Tree *newNode = (Tree*)malloc(sizeof(Tree));
    Tree *actualNode = *binTree;

    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;

    if (actualNode == NULL) {
        *binTree = newNode;
        return;
    }

    while (actualNode->left != NULL && actualNode->right != NULL) {
        if (val >= actualNode->val) {
            if (actualNode->right == NULL) break;

            actualNode = actualNode->right;
        } else {
            if (actualNode->left == NULL) break;

            actualNode = actualNode->left;
        }
    }

    if (val >= actualNode->val) {
        actualNode->right = newNode;
    } else {
        actualNode->left = newNode;
    }
}

Tree* findMin(Tree* binTree) {
    while (binTree->left != NULL)
        binTree = binTree->left;
    return binTree;
}

Tree* popTree(Tree* binTree, int val) {
    if (binTree == NULL) return binTree;

    if (val < binTree->val)
        binTree->left = popTree(binTree->left, val);
    else if (val > binTree->val)
        binTree->right = popTree(binTree->right, val);
    else {
        if (binTree->left == NULL) {
            Tree* aux = binTree->right;
            free(binTree);
            return aux;
        }
        else if (binTree->right == NULL) {
            Tree* aux = binTree->left;
            free(binTree);
            return aux;
        }

        Tree* aux = findMin(binTree->right);
        binTree->val = aux->val;
        binTree->right = popTree(binTree->right, aux->val);
    }

    return binTree;
}

int buscaBin(Tree *binTree, int val) {
    Tree *actualNode = binTree;

    if (actualNode == NULL) return 0;
    if (actualNode->val == val) return 1;

    if (val >= actualNode->val) {
        return buscaBin(actualNode->right, val);
    } else {
        return buscaBin(actualNode->left, val);
    }
}

void printTree(Tree *binTree) {
    if (binTree == NULL) return;

    printf("%d ", binTree->val);

    printTree(binTree->left);
    printTree(binTree->right);
}

int main() {
    Tree *binTree = NULL;

    pushTree(&binTree, 4);
    pushTree(&binTree, 9);
    pushTree(&binTree, 1);
    pushTree(&binTree, 0);
    pushTree(&binTree, 6);

    printTree(binTree);
    printf("\n");

    popTree(binTree, binTree->val);

    printTree(binTree);
    printf("\n");

    printf("%d\n", buscaBin(binTree, 6));
}
