#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* next;
};

void enqueue(struct Node** front, struct Node** rear, int value);
void dequeue(struct Node** front, struct Node** rear);
int peek(struct Node* front);
void display(struct Node* front);
int isEmpty(struct Node* front);

int main() {
    struct Node* front = NULL;  
    struct Node* rear = NULL;   
    int choice, value;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display queue\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(&front, &rear, value);
                break;
            case 2:
                dequeue(&front, &rear);
                break;
            case 3:
                if (!isEmpty(front)) {
                    printf("Front element is: %d\n", peek(front));
                } else {
                    printf("Queue is empty.\n");
                }
                break;
            case 4:
                display(front);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}


void enqueue(struct Node** front, struct Node** rear, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    newNode->data = value;
    newNode->next = NULL;

    if (*rear == NULL) {  
        *front = *rear = newNode;
    } else {
        (*rear)->next = newNode;
        *rear = newNode;
    }
    printf("Enqueued %d into the queue.\n", value);
}


void dequeue(struct Node** front, struct Node** rear) {
    if (*front == NULL) {
        printf("Queue underflow. Queue is empty.\n");
        return;
    }
    struct Node* temp = *front;
    *front = (*front)->next;

    if (*front == NULL) {
        *rear = NULL;  
    }

    printf("Dequeued %d from the queue.\n", temp->data);
    free(temp);
}

// Peek at the front element of the queue
int peek(struct Node* front) {
    if (front != NULL) {
        return front->data;
    }
    return -1; 
}


void display(struct Node* front) {
    if (front == NULL) {
        printf("Queue is empty.\n");
        return;
    }
    struct Node* temp = front;
    printf("Queue elements: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}


int isEmpty(struct Node* front) {
    return front == NULL;
}
