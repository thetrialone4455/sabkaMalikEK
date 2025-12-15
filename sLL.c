#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void insertAtBeginning(int value) {
    struct Node* newNode = createNode(value);
    newNode->next = head;
    head = newNode;
}

void insertAtEnd(int value){
    struct Node* node = createNode(value);
    struct Node* temp = head;
    
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = node;
    node->next = NULL;
}

void insertAtMiddle(int middle, int value){
    struct Node* node = createNode(value);
    struct Node* temp = head;
    
    while(temp->data != middle){
        temp = temp->next;
    }
    node->next = temp->next;
    temp->next = node;
}

void deleteNode(int value){
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    if (head->data == value) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
        return;
    }

    struct Node* temp = head;
    while (temp->next != NULL && temp->next->data != value) {
        temp = temp->next;
    }

    if (temp->next == NULL) {
        printf("Value %d not found in list!\n", value);
        return;
    }

    struct Node* del = temp->next;
    temp->next = del->next;
    free(del);
}

void search(int value){
    if(!head){
        printf("NO HEAD FOUND");
        return;
    }
    struct Node* temp = head;
    while (temp != NULL && temp->data != value) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("NOT FOUND\n");
    } else {
        printf("VALUE FOUND\n");
    }
}

int main() {
    insertAtBeginning(10);
    insertAtEnd(20);
    insertAtEnd(30);
    insertAtEnd(50);
    insertAtMiddle(10, 40);
    search(60);

    struct Node* temp = head;
    while(temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL");

    return 0;
}
