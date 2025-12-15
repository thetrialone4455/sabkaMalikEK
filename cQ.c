#include<stdio.h>

int queue[5];
int rear = -1;
int front = -1;

void enqueue(int i){
    if(((rear + 1) % 5) == front){
        printf("OverFlow\n");
        return;
    }
    
    if(front == -1)
        front = 0;
        
    rear = (rear + 1) % 5;
    queue[rear] = i;
    
}
void dequeue(){
    if(front == -1){
        printf("UnderFlow \n");
        return;
    }
    printf("Deleted Element: %d \n", queue[front]);
    
    if(front == rear)
        front = rear = -1;
    else
        front = (front + 1) % 5;
}

void display(){
    if(front == -1){
        printf("UnderFlow \n");
        return;
    }
    int i = front; // why i = front?, because we dont want to lose the index of front value to further access the queue
    while (1) {
        printf("%d ", queue[i]);
        
        if (i == rear) // the same case is front == rear, i.e. queue is not empty
            break;
            
        i = (i + 1) % 5;
    }
    printf("\n");
}

int main(){
    
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);

    display();

    dequeue();
    dequeue();

    display();

    enqueue(50);
    enqueue(60);

    display();

    return 0;
}