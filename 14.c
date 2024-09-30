#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};


void push(struct Node** top, int value);
void pop(struct Node** top);
int peek(struct Node* top);
void display(struct Node* top);
int isEmpty(struct Node* top);

int main() {
    struct Node* top = NULL;  
    int choice, value;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display stack\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(&top, value);
                break;
            case 2:
                pop(&top);
                break;
            case 3:
                if (!isEmpty(top)) {
                    printf("Top element is: %d\n", peek(top));
                } else {
                    printf("Stack is empty.\n");
                }
                break;
            case 4:
                display(top);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}


void push(struct Node** top, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    newNode->data = value;
    newNode->next = *top;
    *top = newNode;
    printf("Pushed %d onto the stack.\n", value);
}


void pop(struct Node** top) {
    if (*top == NULL) {
        printf("Stack underflow. Stack is empty.\n");
        return;
    }
    struct Node* temp = *top;
    *top = (*top)->next;
    printf("Popped %d from the stack.\n", temp->data);
    free(temp);
}


int peek(struct Node* top) {
    if (top != NULL) {
        return top->data;
    }
    return -1; 


void display(struct Node* top) {
    if (top == NULL) {
        printf("Stack is empty.\n");
        return;
    }
    struct Node* temp = top;
    printf("Stack elements: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}


int isEmpty(struct Node* top) {
    return top == NULL;
}
