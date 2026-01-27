#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
}node;

node *head = NULL;

node *create_node(int value){
    node *new_node = (node *)malloc(sizeof(node));
    if(!new_node) printf("Memory Allocation Failed!\n");
    new_node->data = value;
    new_node->next = new_node;
    return new_node;
}

/*
    The new node becomes the head
    The last node must point to this new head
*/

void insert_begin(int value){
    node *new_node = create_node(value);
    // if list is empty
    if(head == NULL){
        head = new_node; // new node becomes the first node
        new_node->next = new_node; // new node points itself
        return;
    }
    // else
    node *temp = head;
    while(temp->next != head){
        temp = temp->next;
    }
    temp->next = new_node; // connect last node to new node
    new_node->next = head; // make new node point to old node
    head = new_node;
}

void insert_end(int value){
    node *new_node = create_node(value);
    if(head == NULL){
        head = new_node;
        new_node->next = new_node;
        return;
    }
    node *temp = head;
    while(temp->next != head){
        temp = temp->next;
    }
    temp->next = new_node; // last -> new node 
    new_node->next = head; // new node --> head
}

void delete_begin(){
    if(head == NULL) return;
    if(head->next == head){ // list has only one node
        free(head);
        head = NULL;
        return;
    }
    node *temp = head; // store the old head
    node *last = head; // find the last node
    while(last->next != head){
        last = last->next;
    }
    head = head->next; // move original head to the next node
    last->next = head; // update last node's link 
    free(temp); // free old head
}

void delete_end(){
    if(head == NULL) return;
    if(head->next == head){
        free(head);
        head = NULL;
        return;
    }
    // traverse to last node, keep track of previous
    node *temp = head;
    node *prev = NULL;
    while(temp->next != head){
        prev = temp;
        temp = temp->next;
    }
    prev->next = head; // link second last node to head
    free(temp);
}

/*
    Since there is no null, use do-while
    Start from head, stop when we reach head again
*/

void display(){
    if(head == NULL) return;
    node *temp = head;
    do{
        printf("%d ", temp->data);
        temp = temp->next;
    } while(temp != head);
    printf("\n");
}

int main(){

    insert_begin(10);
    insert_begin(20);
    insert_begin(30);
    insert_begin(40);
    insert_begin(50);

    display();
    
    return 0;
}