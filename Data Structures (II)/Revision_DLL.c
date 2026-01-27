#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
}node;

node *head = NULL;
node *tail = NULL;

node *create_node(int value){
    node *newNode = (node *)malloc(sizeof(node));
    if(!newNode) return NULL;
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

node *insert_beginning(int value){
    node *newNode = create_node(value);
    // if empty
    if(head == NULL){
        head = newNode;
        tail = newNode;
        return newNode;
    }
    // insert using head
    newNode->next = head; 
    head->prev = newNode;
    head = newNode; // update head
    return newNode;
}

node *insert_end_m1(int value){
    node *newNode = create_node(value);
    // case:1 if empty list
    if(head == NULL){
        head = newNode;
        tail = newNode;
        return newNode;
    }
    // traverse
    node *temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
    tail = newNode;
    return head;
}

node *insert_end_m2(int value){
    node *newNode = create_node(value);
    if(head == NULL){
        head = newNode;
        tail = newNode;
        return newNode;
    }
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
    return head;
}

node *insert_between(int value, int pos){
    if(pos < 0) return head;
    node *newNode = create_node(value);

    // case:1 empty list
    if(head == NULL){
        head = newNode;
        tail = newNode;
        return head;
    }
    // case:2 insert at beginning
    if(pos == 0){
        newNode->next = head; 
        head->prev = newNode;
        head = newNode; // update head
        return head;
    }
    // case:3 traverse to pos 
    node *temp = head;
    int i = 0;
    while(temp != NULL && i < pos - 1){
        temp = temp->next;
        i++;
    }
    // case:4 position out of bounds
    if(temp == NULL){
        free(newNode);
        return head;
    }
    // case:5 insert at the end
    if(temp->next == NULL){
        temp->next = newNode;
        newNode->prev = temp;
        tail = newNode;
        return head;
    }
    // case:6 insert between the nodes
    newNode->next = temp->next;
    newNode->prev = temp;
    temp->next->prev = newNode;
    temp->next = newNode;
    return head;
}

node *delete_beginning(){
    // if empty
    if(head == NULL){
        return NULL;
    }
    node *temp = head; // old pointer
    // if one node
    if(head->next == NULL){
        head = NULL;
        tail = NULL;
        free(temp);
        return NULL;
    }
    // more than one node
    head = head->next;
    head->prev = NULL;
    free(temp);
    return head;
}

node *delete_end(){
    if(head == NULL) return NULL;
    //if one node
    if(head->next == NULL){
        free(head);
        head = NULL;
        tail = NULL;
        return NULL;
    }
    // more than one end
    node *oldTail = tail;
    tail = tail->prev;
    tail->next = NULL;
    free(oldTail);
    return head;
}

node *delete_position(int pos){
    // case:1 invalid position
    if(pos < 0 || head == NULL) return head;
    
    // case:2 delete first node
    if(pos == 0){
        node *temp = head; // old pointer
        // if one node
        if(head->next == NULL){
            head = NULL;
            tail = NULL;
            free(temp);
            return NULL;
        }
        // more than one node
        head = head->next;
        head->prev = NULL;
        free(temp);
        return head;  
    }
    // case:3 traverse to pos
    node *temp = head;
    int i = 0;
    while(temp != NULL && i < pos){
        temp = temp->next;
        i++;
    }

    // case:4 out of bounds
    if(temp == NULL){
        return head;
    }

    // case:5 delete last node
    if(temp->next == NULL){
        tail = temp->prev;
        tail->next = NULL;
        free(temp);
        return head;
    }

    // case:6 delete from middle
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    free(temp);
    return head;
}

void forward_traversal(){
    node *temp = head;
    if(temp == NULL){ 
        printf("List is empty\n"); 
        return;
    }
    printf("Forward Traversal: \n");
    while(temp != NULL){
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void backward_traversal(){
    node *temp = tail;
    if(temp == NULL){ 
        printf("List is empty\n"); 
        return;
    }
    printf("Backward Traversal: \n");
    while(temp != NULL){
        printf("%d <-> ", temp->data);
        temp = temp->prev;
    }
    printf("NULL\n");
}

int main() {
    int choice, value, pos;

    while(1) {
        printf("\n===== DOUBLY LINKED LIST MENU =====\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End (Method 1)\n");
        printf("3. Insert at End (Method 2)\n");
        printf("4. Insert at Position\n");
        printf("5. Delete at Beginning\n");
        printf("6. Delete at End\n");
        printf("7. Delete at Position\n");
        printf("8. Forward Traversal\n");
        printf("9. Backward Traversal\n");
        printf("10. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insert_beginning(value);
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                insert_end_m1(value);
                break;

            case 3:
                printf("Enter value: ");
                scanf("%d", &value);
                insert_end_m2(value);
                break;

            case 4:
                printf("Enter value: ");
                scanf("%d", &value);
                printf("Enter position: ");
                scanf("%d", &pos);
                insert_between(value, pos);
                break;

            case 5:
                delete_beginning();
                break;

            case 6:
                delete_end();
                break;

            case 7:
                printf("Enter position: ");
                scanf("%d", &pos);
                delete_position(pos);
                break;

            case 8:
                forward_traversal();
                break;

            case 9:
                backward_traversal();
                break;

            case 10:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
