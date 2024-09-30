#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};


void insertAtFront(struct Node** head, int value);
void insertAtEnd(struct Node** head, int value);
void deleteLastNode(struct Node** head);
void deleteBeforePosition(struct Node** head, int pos);
void traverse(struct Node* head);

int main() {
    struct Node* head = NULL;  
    int choice, value, pos;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert at front\n");
        printf("2. Insert at end\n");
        printf("3. Delete last node\n");
        printf("4. Delete node before specified position\n");
        printf("5. Traverse the list\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert at front: ");
                scanf("%d", &value);
                insertAtFront(&head, value);
                break;
            case 2:
                printf("Enter value to insert at end: ");
                scanf("%d", &value);
                insertAtEnd(&head, value);
                break;
            case 3:
                deleteLastNode(&head);
                break;
            case 4:
                printf("Enter position before which to delete: ");
                scanf("%d", &pos);
                deleteBeforePosition(&head, pos);
                break;
            case 5:
                traverse(head);
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}


void insertAtFront(struct Node** head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    newNode->data = value;
    newNode->next = *head;
    newNode->prev = NULL;

    if (*head != NULL) {
        (*head)->prev = newNode;
    }

    *head = newNode;
    printf("Inserted %d at the front of the list.\n", value);
}

void insertAtEnd(struct Node** head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node* temp = *head;

    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    newNode->data = value;
    newNode->next = NULL;

    if (*head == NULL) {
        newNode->prev = NULL;
        *head = newNode;
        return;
    }

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;

    printf("Inserted %d at the end of the list.\n", value);
}


void deleteLastNode(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = *head;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    if (temp->prev != NULL) {
        temp->prev->next = NULL;
    } else {
        *head = NULL;  
    }

    free(temp);
    printf("Last node deleted.\n");
}


void deleteBeforePosition(struct Node** head, int pos) {
    if (*head == NULL || pos <= 1) {
        printf("Invalid position or no node before this position.\n");
        return;
    }

    struct Node* temp = *head;

    
    for (int i = 1; temp != NULL && i < pos - 1; i++) {
        temp = temp->next;
    }

    if (temp == NULL || temp->prev == NULL) {
        printf("No node before this position.\n");
        return;
    }

    struct Node* nodeToDelete = temp->prev;

    if (nodeToDelete->prev != NULL) {
        nodeToDelete->prev->next = temp;
    } else {
        *head = temp;
    }

    temp->prev = nodeToDelete->prev;

    free(nodeToDelete);
    printf("Node before position %d deleted.\n", pos);
}


void traverse(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
