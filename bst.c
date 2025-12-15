#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};


struct Node* createNode(int value){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* insertNode(struct Node* root, int value){
    if(root == NULL){
        return createNode(data);
    }
    if(value < root->data){
        root->left = insertNode(root->left, value);
    }
    else if(value > root->data){
        root->right = insertNode(root->right, value);
    }
    else{
        printf("DUPLICATE VALUE");
    }
}

bool search(struct Node* root, int value){
    if(root == NULL)
        return false;
    if(root->data == value)
        return true;
    if(value < root->data)
        return search(root->left, value);
    else if(value > root->data)
        return search(root->right, value);
}

struct Node* findMin(struct Node* root){  // required for deleting node
    while(root && root->left != NULL){
        root = root->left;
    }
    return root;
}

struct Node* deleting(struct Node* root, int value) {
    if(root == NULL)
        return NULL;

    if(value < root->data) {
        root->left = deleting(root->left, value);
    }
    else if(value > root->data) {
        root->right = deleting(root->right, value);
    }
    else {
        // Node found

        // Case 1: no child
        if(root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        }
        // Case 2: only right child
        else if(root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        }
        // Case 2: only left child
        else if(root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }
        // Case 3: two children
        else {
            struct Node* temp = findMin(root->right);  // inorder successor
            root->data = temp->data;                   // copy value
            root->right = deleting(root->right, temp->data); // delete successor
        }
    }
    return root;
}

int main(){
    
    return 0;
}