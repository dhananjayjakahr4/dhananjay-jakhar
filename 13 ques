#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* next;
};


void insertAtFront(struct Node** head, int data);
void insertAtEnd(struct Node** head, int data);
void insertInOrder(struct Node** head, int data);
void deleteFirstNode(struct Node** head);
void deleteBeforePosition(struct Node** head, int pos);
void deleteAfterPosition(struct Node** head, int pos);
void traverse(struct Node* head);

int main() {
    struct Node* head = NULL;
    int choice, value, pos;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert at front\n");
        printf("2. Insert at end\n");
        printf("3. Insert in ascending order\n");
        printf("4. Delete first node\n");
        printf("5. Delete node before position\n");
        printf("6. Delete node after position\n");
        printf("7. Traverse the list\n");
        printf("8. Exit\n");
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
                printf("Enter value to insert in ascending order: ");
                scanf("%d", &value);
                insertInOrder(&head, value);
                break;
            case 4:
                deleteFirstNode(&head);
                break;
            case 5:
                printf("Enter position before which to delete: ");
                scanf("%d", &pos);
                deleteBeforePosition(&head, pos);
                break;
            case 6:
                printf("Enter position after which to delete: ");
                scanf("%d", &pos);
                deleteAfterPosition(&head, pos);
                break;
            case 7:
                traverse(head);
                break;
            case 8:
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}


void insertAtFront(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}


void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node* temp = *head;

    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}


void insertInOrder(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node* current;

    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL || (*head)->data >= data) {
        newNode->next = *head;
        *head = newNode;
    } else {
        current = *head;
        while (current->next != NULL && current->next->data < data) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}


void deleteFirstNode(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = *head;
    *head = (*head)->next;
    free(temp);
    printf("First node deleted.\n");
}


void deleteBeforePosition(struct Node** head, int pos) {
    if (pos <= 1 || *head == NULL || (*head)->next == NULL) {
        printf("Invalid position or no node to delete before this position.\n");
        return;
    }

    struct Node* temp = *head;
    struct Node* prev = NULL;

    if (pos == 2) { // Delete the first node
        deleteFirstNode(head);
        return;
    }

    for (int i = 1; temp != NULL && i < pos - 1; i++) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL) {
        printf("No node before this position.\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
    printf("Node before position %d deleted.\n", pos);
}


void deleteAfterPosition(struct Node** head, int pos) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = *head;

    for (int i = 1; temp != NULL && i < pos; i++) {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL) {
        printf("No node after this position.\n");
        return;
    }

    struct Node* nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    free(nodeToDelete);
    printf("Node after position %d deleted.\n", pos);
}


void traverse(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
