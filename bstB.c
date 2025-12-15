#include <iostream>
#include <cstdlib>
using namespace std;

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int x) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

void preorder(struct Node* root) {
    if (root != NULL) {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
}

int countNodes(struct Node* root) {
    if (root == NULL)
        return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

void mirrorTree(struct Node* root) {
    if (root == NULL)
        return;

    struct Node* temp = root->left;
    root->left = root->right;
    root->right = temp;

    mirrorTree(root->left);
    mirrorTree(root->right);
}

#define MAX 50
struct Node* stackArr[MAX];
int top = -1;

void push(struct Node* x) {
    stackArr[++top] = x;
}

struct Node* pop() {
    return stackArr[top--];
}

int isEmpty() {
    return top == -1;
}

void inorderNR(struct Node* root) {
    struct Node* curr = root;

    while (curr != NULL || !isEmpty()) {
        while (curr != NULL) {
            push(curr);
            curr = curr->left;
        }
        curr = pop();
        cout << curr->data << " ";
        curr = curr->right;
    }
}

void preorderNR(struct Node* root) {
    if (root == NULL) return;

    push(root);
    while (!isEmpty()) {
        struct Node* curr = pop();
        cout << curr->data << " ";

        if (curr->right != NULL)
            push(curr->right);
        if (curr->left != NULL)
            push(curr->left);
    }
}

void postorderNR(struct Node* root) {
    struct Node* stack1[MAX];
    struct Node* stack2[MAX];
    int t1 = -1, t2 = -1;

    stack1[++t1] = root;

    while (t1 != -1) {
        struct Node* curr = stack1[t1--];
        stack2[++t2] = curr;

        if (curr->left != NULL)
            stack1[++t1] = curr->left;
        if (curr->right != NULL)
            stack1[++t1] = curr->right;
    }

    while (t2 != -1) {
        cout << stack2[t2--]->data << " ";
    }
}

int main() {
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    cout << "Recursive Inorder: ";
    inorder(root);
    cout << endl;

    cout << "Recursive Preorder: ";
    preorder(root);
    cout << endl;

    cout << "Recursive Postorder: ";
    postorder(root);
    cout << endl;

    cout << "Total Nodes: " << countNodes(root) << endl;

    mirrorTree(root);
    cout << "Inorder after Mirror: ";
    inorder(root);
    cout << endl;

    cout << "Non-Recursive Inorder: ";
    inorderNR(root);
    cout << endl;

    cout << "Non-Recursive Preorder: ";
    preorderNR(root);
    cout << endl;

    cout << "Non-Recursive Postorder: ";
    postorderNR(root);
    cout << endl;

    return 0;
}