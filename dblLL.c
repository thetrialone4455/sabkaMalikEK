#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct Node{
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* head = NULL;

struct Node* createNode(int value){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    
    return newNode;
}

void insertAtBeginning(int value){
    struct Node* newNode = createNode(value);
    
    newNode->next = head;
    newNode->prev = NULL;
    
    if(head != NULL){ // agar list empty nhi h, toch pehle ka head ko prev pointer use kar, nhi toh
        head->prev = newNode; // direct newNode hi head huila naaaa
    }
    
    head = newNode;
}

void insertAtEnd(int value){
    struct Node* newNode = createNode(value);
    
    if(head == NULL){
        head = newNode;
        return;
    }
    struct Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

bool insertAtMiddle(int middle, int value){
    struct Node* newNode = createNode(value);
    
    if(head == NULL){
        head = newNode;
    }
    struct Node* temp = head;
    
    while(temp != NULL && temp->data != middle){
        temp = temp->next;
    }
    if(temp == NULL){
        return false;
    }
    
    newNode->prev = temp;
    newNode->next = temp->next;
    
    if(temp->next != NULL){ // yo edge case solve kre ki, if middle value hi last element h toh uro 
        temp->next->prev = newNode; // ->next ptr toh NULL rhila, and agar ya scene pe next ptr ko prev
    }                              // ptr agar newNode ne pt karyo toh segment error aaila.....
    temp->next = newNode;
}

bool deletion(int value){
    if(head == NULL){
        return false;
    }
    struct Node* temp = head;
    if(temp->data == value){
        head = temp->next;
        if(head != NULL){
            head->prev = NULL;
        }
        free(temp);
        return true;
    }
    
    while(temp!= NULL && temp->data != value){
        temp = temp->next;
    }
    if(temp == NULL){
        return false;
    }
    if(temp->next == NULL){
        temp->prev->next = NULL;
        free(temp);
        return true;
    }
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    free(temp);
    return true;
}

bool search(int value){
    struct Node* temp = head;
    while(temp != NULL){ // abb dekh aate temp->next != null kyu nhi aayo, scene aiso h ki, tu last node
        if(temp->data == value){ // pe gyo and vate obviously lastNode->next == NULL hi rhila, toh voh na
            return true;        // loop ka bare aajaila, and joh last node m if ki condition ko comparision
        }                      // h, voh nhi huila, mltb ki last element ki value compare hi nhi huila
        temp = temp->next;
    }
    return false;
}

void printList(){
    struct Node* temp = head;
    printf("DLL: ");
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// ---------------------- MAIN ----------------------
int main(){
    insertAtBeginning(20);
    insertAtBeginning(10);
    insertAtEnd(30);
    insertAtEnd(40);
    insertAtMiddle(20, 25);    // insert 25 after 20

    printf("After insertions:\n");
    printList();

    deletion(10);     // delete head
    deletion(30);     // delete middle
    deletion(40);     // delete last

    printf("After deletions:\n");
    printList();

    return 0;
}