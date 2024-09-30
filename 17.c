#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* next;
};


void insertAtEnd(struct Node** head, int value);
void insertBeforePosition(struct Node** head, int value, int pos);
void deleteFirstNode(struct Node** head);
void deleteAfterPosition(struct Node** head, int pos);
void traverse(struct Node* head);

int main() {
    struct Node* head = NULL;  
    int choice, value, pos;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert at end\n");
        printf("2. Insert before specified position\n");
        printf("3. Delete first node\n");
        printf("4. Delete node after specified position\n");
        printf("5. Traverse the list\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert at end: ");
                scanf("%d", &value);
                insertAtEnd(&head, value);
                break;
            case 2:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                printf("Enter position before which to insert: ");
                scanf("%d", &pos);
                insertBeforePosition(&head, value, pos);
                break;
            case 3:
                deleteFirstNode(&head);
                break;
            case 4:
                printf("Enter position after which to delete: ");
                scanf("%d", &pos);
                deleteAfterPosition(&head, pos);
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


void insertAtEnd(struct Node** head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node* temp = *head;
    newNode->data = value;
    newNode->next = NULL;

    if (*head == NULL) {  
        *head = newNode;
        newNode->next = newNode;
    } else {
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = *head; 
    }
    printf("Inserted %d at the end of the list.\n", value);
}

void insertBeforePosition(struct Node** head, int value, int pos) {
    if (pos <= 1 || *head == NULL) {
        printf("Invalid position or list is empty.\n");
        return;
    }

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;

    if (pos == 2) {  
        newNode->next = (*head)->next;
        (*head)->next = newNode;
    } else {
        struct Node* temp = *head;
        int count = 1;

        while (count < pos - 1 && temp->next != *head) {
            temp = temp->next;
            count++;
        }

        if (count == pos - 1) {
            newNode->next = temp->next;
            temp->next = newNode;
        } else {
            printf("Position out of bounds.\n");
        }
    }

    printf("Inserted %d before position %d.\n", value, pos);
}


void deleteFirstNode(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = *head;

    if (temp->next == *head) { 
        free(temp);
        *head = NULL;
    } else {
        struct Node* last = *head;
        while (last->next != *head) {
            last = last->next;
        }
        *head = (*head)->next;
        last->next = *head;
        free(temp);
    }

    printf("First node deleted.\n");
}


void deleteAfterPosition(struct Node** head, int pos) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = *head;
    int count = 1;

    while (count < pos && temp->next != *head) {
        temp = temp->next;
        count++;
    }

    if (count == pos && temp->next != *head) {
        struct Node* nodeToDelete = temp->next;
        temp->next = nodeToDelete->next;

        if (nodeToDelete == *head) {  
            *head = nodeToDelete->next;
        }

        free(nodeToDelete);
        printf("Node after position %d deleted.\n", pos);
    } else {
        printf("Position out of bounds or no node to delete after specified position.\n");
    }
}


void traverse(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = head;
    printf("Circular Linked List: ");
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(head)\n");
}
